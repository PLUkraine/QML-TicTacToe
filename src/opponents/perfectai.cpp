#include "opponents/perfectai.h"
#include <QtConcurrent/QtConcurrentRun>
#include <QDebug>

using std::get;

PerfectAi::PerfectAi(QObject *parent)
    : IGameOpponent(parent),
      m_cancel(false)
{
}

PerfectAi::~PerfectAi()
{
    __cancelComputation();
}

void PerfectAi::startComputation(GameBoard *board, bool isXTurn)
{
    m_cancel = false;
    m_computationFuture = QtConcurrent::run(this, &PerfectAi::threadFunction, board, isXTurn);
}

int PerfectAi::startBlockingComputation(GameBoard *board, bool isXTurn)
{
    m_cancel = false;
    int result = threadFunction(board, isXTurn);
    return result;
}

void PerfectAi::cancelComputation()
{
    __cancelComputation();
}

void PerfectAi::__cancelComputation()
{
    m_cancel = true;
    m_computationFuture.waitForFinished();
}

int PerfectAi::threadFunction(GameBoard *board, bool isXTurn)
{
    ScoreIndexDepth result = minMax(board, isXTurn ? CellStateEnum::X :CellStateEnum::O, true, 0);
    //    qDebug() << "Score" << get<0>(result) << "Index" << get<1>(result) << "Depth" << get<2>(result);

    int answer = get<1>(result);
    if (!m_cancel) {
        emit computationEnded(answer);
    }
    return answer;
}

ScoreIndexDepth PerfectAi::minMax(GameBoard *board, CellStateEnum::EnCellState cell, bool isAiTurn, int depth)
{
    ScoreIndexDepth answer = {isAiTurn ? -1e9 : 1e9, -1, -1};

    for (int i=0; i<board->getIndexCount(); ++i) {
        if (m_cancel) return {0, -1, -1};
        if (board->getCell(i) != CellStateEnum::EMPTY) continue;

        board->setCell(i, cell);

        ScoreIndexDepth candidate = getCandidate(board, cell, m_algo.getState(board, i), isAiTurn, i, depth);
        if (isCandidateBetter(answer, candidate, isAiTurn)) {
            answer = {get<0>(candidate), i, get<2>(candidate)};
        }

        board->setCell(i, CellStateEnum::EMPTY);
    }
    return answer;
}

ScoreIndexDepth PerfectAi::getCandidate(GameBoard *board, CellStateEnum::EnCellState cell,
                                        GameStateClass::EnGameState curState, bool isAiTurn,
                                        int curIndex, int depth)
{
    switch (curState) {
    case GameStateClass::STATE_DRAW:
        return {0, curIndex, depth};
    case GameStateClass::STATE_X_WIN:
    case GameStateClass::STATE_O_WIN:
        return {isAiTurn ? 10 : -10, curIndex, depth};
    case GameStateClass::STATE_NOTHING:
        return depth > 4
                ? std::make_tuple(0, curIndex, depth)
                : minMax(board, m_algo.changePlayer(cell), !isAiTurn, depth+1);
    }
    exit(1);
}

// delay the last move for as long as it is possible!!!!
bool PerfectAi::isCandidateBetter(const ScoreIndexDepth &answer, const ScoreIndexDepth &candidate, bool isAiTurn) const
{
    if (isAiTurn) {
        return get<0>(answer) < get<0>(candidate)
                || (get<0>(answer) == get<0>(candidate) && get<2>(answer) < get<2>(candidate));
    }
    else {
        return get<0>(answer) > get<0>(candidate)
                || (get<0>(answer) == get<0>(candidate) && get<2>(answer) > get<2>(candidate));
    }
}
