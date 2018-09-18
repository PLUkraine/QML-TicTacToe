#ifndef PERFECTAI_H
#define PERFECTAI_H

#include <QObject>
#include <QFuture>
#include <tuple>
#include <QAtomicInt>

#include "igameopponent.h"
#include "include/gameboard.h"
#include "include/gamestatealgorithm.h"

typedef std::tuple<int, int, int> ScoreIndexDepth;

class PerfectAi : public IGameOpponent
{
    Q_OBJECT
private:
    GameStateAlgorithm m_algo;
    QFuture<int> m_computationFuture;
    QAtomicInt m_cancel;

public:
    PerfectAi(QObject *parent=nullptr);
    ~PerfectAi() override;

    int startBlockingComputation(GameBoard *board, bool isXTurn);
    void startComputation(GameBoard *board, bool isXTurn) override;
    void cancelComputation() override;

private:
    void __cancelComputation();
    int threadFunction(GameBoard *board, bool isXTurn);
    ScoreIndexDepth minMax(GameBoard *board, CellStateEnum::EnCellState cell, bool isAiTurn, int depth);
    ScoreIndexDepth getCandidate(GameBoard *board, CellStateEnum::EnCellState cell,
                                 GameStateClass::EnGameState curState, bool isAiTurn, int curIndex, int depth);
    bool isCandidateBetter(const ScoreIndexDepth &answer, const ScoreIndexDepth &candidate, bool isAiTurn) const;

};

#endif // PERFECTAI_H
