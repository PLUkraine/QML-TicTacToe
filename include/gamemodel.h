#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "gameboard.h"
#include "gamestatealgorithm.h"

class GameModel {
private:
    int m_cellsToWin;
    GameStateAlgorithm m_stateAlgo;
    GameBoard m_board;
    bool m_playerXTurn;
    bool m_isActive;

public:
    GameModel();

    void startNewGame(int rows, int cols, int cellsToWin);
    GameStateClass::EnGameState makeMove(int row, int col);
    bool isXTurn() const;
    CellStateEnum::EnCellState getCell(int row, int col);
};

#endif // GAMEMODEL_H
