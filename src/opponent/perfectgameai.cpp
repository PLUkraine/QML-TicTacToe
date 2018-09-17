#include "opponent/perfectgameai.h"
#include <QDebug>

PerfectGameAi::PerfectGameAi()
{

}

int PerfectGameAi::makeMove(GameBoard *model, bool isAiX)
{
    CellStateEnum::EnCellState curPlayer = isAiX ? CellStateEnum::X : CellStateEnum::O;
    return std::get<0>(minMaxRecursion(model, curPlayer, isAiX, 0));
}

IndexScoreDepth PerfectGameAi::minMaxRecursion(GameBoard *board, CellStateEnum::EnCellState curPlayer, bool isAiTurn, int depth)
{
    IndexScoreDepth answer = std::make_tuple(-1, isAiTurn ? -100 : 100, -1);

    for (int i=0; i<board->getIndexCount(); ++i) {
        if (board->getCell(i) != CellStateEnum::EMPTY) continue;

        // try this cell
        board->setCell(i, curPlayer);
        // check if game is over
        GameStateClass::EnGameState state = m_stateAlgo.getState(board, i);

//        qDebug() << i << "depth" << depth;
//        board->debugPrint();

        // determine this step's answer
        IndexScoreDepth recursionAnswer;
        // recurse and find answer in child
        if (state == GameStateClass::STATE_NOTHING) {
            recursionAnswer = minMaxRecursion(board,
                                              m_stateAlgo.changePlayer(curPlayer),
                                              !isAiTurn,
                                              depth+1);
        }
        // no one wins
        else if (state == GameStateClass::STATE_DRAW) {
            recursionAnswer = {i, 0, depth};
        }
        // ai wins if this is it's turn
        else {
            recursionAnswer = std::make_tuple(i, isAiTurn ? 10 : -10, depth);
        }

        // check if current cell's answer is better (ai chooses max, 2nd player min)
        if (isNewAnswerBetter(answer, recursionAnswer, isAiTurn)) {
            answer = {i, std::get<1>(recursionAnswer), std::get<2>(recursionAnswer)};
        }

        // don't forget to undo our move!
        board->setCell(i, CellStateEnum::EMPTY);
    }

    return answer;
}

bool PerfectGameAi::isNewAnswerBetter(IndexScoreDepth old, IndexScoreDepth newAnswer, bool isAiTurn) const
{
    bool betterMax = isAiTurn && std::get<1>(old) < std::get<1>(newAnswer);
    bool betterMin = !isAiTurn && std::get<1>(old) > std::get<1>(newAnswer);
    bool sameButDeeper = std::get<1>(old) == std::get<1>(newAnswer)
            && std::get<2>(old) < std::get<2>(newAnswer);

    return betterMin || betterMax || sameButDeeper;
}
