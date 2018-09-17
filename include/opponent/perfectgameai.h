#ifndef PERFECTGAMEAI_H
#define PERFECTGAMEAI_H

#include "igameai.h"
#include "gamestatealgorithm.h"
#include <tuple>

typedef std::tuple<int, int, int> IndexScoreDepth;

class PerfectGameAi : public IGameAI
{
private:
    GameStateAlgorithm m_stateAlgo;

public:
    PerfectGameAi();

    // IGameAI interface
public:
    virtual int makeMove(GameBoard *model, bool isAiX) override;

private:
    IndexScoreDepth minMaxRecursion(GameBoard *board, CellStateEnum::EnCellState curPlayer, bool isAiTurn, int depth);
private:
    bool isNewAnswerBetter(IndexScoreDepth old, IndexScoreDepth newAnswer, bool isAiTurn) const;
};

#endif // PERFECTGAMEAI_H
