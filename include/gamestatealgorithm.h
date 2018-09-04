#ifndef GAMESTATEALGORITHM_H
#define GAMESTATEALGORITHM_H

#include "gameboard.h"
#include "gamestateenum.h"
#include "boarditerator.h"

class GameStateAlgorithm
{
public:
    GameStateAlgorithm();

    GameStateClass::EnGameState getState(GameBoard *board, int changedIndex, int cellsToWin);

private:
    bool checkPath(GameBoard *board, BoardIterator *iterator, int cellsToWin);
    GameStateClass::EnGameState determineWinner(GameBoard *board, int pos);
};

#endif // GAMESTATEALGORITHM_H
