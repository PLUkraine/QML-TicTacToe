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

        board->setCell(i, curPlayer);

        GameStateClass::EnGameState state = m_stateAlgo.getState(board, i);

        IndexScore recursionAnswer;
        if (state == GameStateClass::STATE_NOTHING) {
            recursionAnswer = minMaxRecursion(board,
                                              m_stateAlgo.changePlayer(curPlayer),
                                              !isAiTurn);
        }
        else if (state == GameStateClass::STATE_DRAW) {
            recursionAnswer = {i, 0};
        }
        else {
            recursionAnswer = std::make_pair(i, isAiTurn ? 10 : -10);
        }

        if ((isAiTurn && answer.second < recursionAnswer.second) ||
                (!isAiTurn && answer.second > recursionAnswer.second)) {
            answer = {i, recursionAnswer.second};
        }

        board->setCell(i, CellStateEnum::EMPTY);
    }

    return answer;
}
