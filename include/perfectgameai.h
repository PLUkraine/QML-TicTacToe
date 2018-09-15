#ifndef PERFECTGAMEAI_H
#define PERFECTGAMEAI_H

#include "igameai.h"
#include <utility>
#include "gamestatealgorithm.h"

typedef std::pair<int, int> IndexScore;

class PerfectGameAi : public IGameAI
{
private:
    GameStateAlgorithm m_stateAlgo;

public:
    PerfectGameAi();

    // IGameAI interface
public:
    virtual int makeMove(GameBoard *model, bool isAiX, bool isXTurn, int cellsTiWin) override;

private:
    IndexScore minMaxRecursion(GameBoard *board, CellStateEnum::EnCellState curPlayer, bool isAiTurn, int cellsToWin);
};

#endif // PERFECTGAMEAI_H
