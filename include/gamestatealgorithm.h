#ifndef GAMESTATEALGORITHM_H
#define GAMESTATEALGORITHM_H

#include "gameboard.h"
#include "boarditerator.h"

enum class GameState: char {
    NOTHING, X_WIN, O_WIN, DRAW
};

class GameStateAlgorithm
{
public:
    GameStateAlgorithm();

    GameState getState(GameBoard *board, int changedIndex, int cellsToWin);

private:
    bool checkPath(GameBoard *board, BoardIterator *iterator, int cellsToWin);
    GameState determineWinner(GameBoard *board, int pos);
};

#endif // GAMESTATEALGORITHM_H
