#include "perfectgameai.h"

PerfectGameAi::PerfectGameAi()
{

}

int PerfectGameAi::makeMove(GameBoard *model, bool isAiX, bool isXTurn)
{
    CellStateEnum::EnCellState curPlayer = isXTurn ? CellStateEnum::X : CellStateEnum::O;
    return minMaxRecursion(model, curPlayer, isAiX == isXTurn).first;
}

IndexScore PerfectGameAi::minMaxRecursion(GameBoard *board, CellStateEnum::EnCellState curPlayer, bool isAiTurn)
{
    IndexScore answer = std::make_pair(-1, isAiTurn ? -100 : 100);

    for (int i=0; i<board->getIndexCount(); ++i) {
        if (board->getCell(i) != CellStateEnum::EMPTY) continue;

        // try this cell
        board->setCell(i, curPlayer);
        // check if game is over
        GameStateClass::EnGameState state = m_stateAlgo.getState(board, i);

        // determine this step's answer
        IndexScore recursionAnswer;
        // recurse and find answer in child
        if (state == GameStateClass::STATE_NOTHING) {
            recursionAnswer = minMaxRecursion(board,
                                              m_stateAlgo.changePlayer(curPlayer),
                                              !isAiTurn);
        }
        // no one wins
        else if (state == GameStateClass::STATE_DRAW) {
            recursionAnswer = {i, 0};
        }
        // ai wins if this is it's turn
        else {
            recursionAnswer = std::make_pair(i, isAiTurn ? 10 : -10);
        }

        // check if current cell's answer is better (ai chooses max, 2nd player min)
        if ((isAiTurn && answer.second < recursionAnswer.second) ||
                (!isAiTurn && answer.second > recursionAnswer.second)) {
            answer = {i, recursionAnswer.second};
        }

        // don't forget to undo our move!
        board->setCell(i, CellStateEnum::EMPTY);
    }

    return answer;
}
