#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "gameboard.h"
#include "gamestatealgorithm.h"

class GameModel : public QObject {
    Q_OBJECT

private:
    GameStateAlgorithm m_stateAlgo;
    GameBoard m_board;
    bool m_playerXTurn;
    bool m_isActive;

public:
    GameModel(QObject *parent = nullptr);

    void startNewGame(int rows, int cols, int cellsToWin);
    void makePlayerMove(int index);


    CellStateEnum::EnCellState getCell(int index) const;
    int getIndex(int row, int col) const;
    bool isXTurn() const;

signals:
    void playerChanged(bool isXPlayer);
    void cellChanged(int index, int cellValue);
    void gameIsOver(GameStateClass::EnGameState state);

private:
    void flipPlayer();
    void resetPlayer();
    void setCell(int index);
    void computeState(int changedIndex);
};

#endif // GAMEMODEL_H
