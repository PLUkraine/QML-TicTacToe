#ifndef PERFECTGAMEAI_H
#define PERFECTGAMEAI_H

#include "igameai.h"
#include "gamestatealgorithm.h"
#include <utility>

typedef std::pair<int, int> IndexScore;

class PerfectGameAi : public IGameAI
{
private:
    GameStateAlgorithm m_stateAlgo;

public:
    PerfectGameAi();

    // IGameAI interface
public:
    virtual int makeMove(GameBoard *model, bool isAiX, bool isXTurn) override;

private:
    IndexScore minMaxRecursion(GameBoard *board, CellStateEnum::EnCellState curPlayer, bool isAiTurn);
};

#endif // PERFECTGAMEAI_H
