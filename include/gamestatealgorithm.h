#ifndef GAMESTATEALGORITHM_H
#define GAMESTATEALGORITHM_H

#include "gameboard.h"
#include "gamestateenum.h"
#include "boarditerator.h"

class GameStateAlgorithm
{
public:
    GameStateAlgorithm();

    GameStateClass::EnGameState getState(GameBoard *board, int changedIndex, int cellsToWin) const;
    CellStateEnum::EnCellState changePlayer(CellStateEnum::EnCellState curPlayer) const;

private:
    bool checkPath(GameBoard *board, BoardIterator *iterator, int cellsToWin) const;
    GameStateClass::EnGameState determineWinner(GameBoard *board, int pos) const;
};

#endif // GAMESTATEALGORITHM_H
