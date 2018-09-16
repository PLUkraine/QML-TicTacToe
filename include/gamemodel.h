#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <memory>

#include "opponent/basegameopponent.h"
#include "gameboard.h"
#include "gamestatealgorithm.h"

class GameModel {
private:
    GameStateAlgorithm m_stateAlgo;
    GameBoard m_board;
    std::unique_ptr<BaseGameOpponent> m_opponent;
    bool m_playerXTurn;
    bool m_isActive;

public:
    GameModel();

    void startNewGame(int rows, int cols, int cellsToWin);
    GameStateClass::EnGameState makePlayerMove(int index);
    CellStateEnum::EnCellState getCell(int index) const;
    int getIndex(int row, int col) const;
    bool isXTurn() const;
};

#endif // GAMEMODEL_H
