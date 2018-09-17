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
    bool m_isOpponentTurn;

public:
    GameModel(QObject *parent = nullptr);

    void startNewGame(int rows, int cols, int cellsToWin);
    void makePlayerMove(int index);
    void makeOpponentMove();


    CellStateEnum::EnCellState getCell(int index) const;
    int getIndex(int row, int col) const;
    bool isXTurn() const;
    bool isOpponentTurn() const;

signals:
    void isOpponentTurnChanged(bool isOpponentTurn);
    void playerChanged(bool isXPlayer);
    void cellChanged(int index, int cellValue);
    void gameIsOver(GameStateClass::EnGameState state);

private:
    void setOpponentTurn(bool value);
    void flipPlayer();
    void resetPlayer();
    void setCell(int index);
    void computeState(int changedIndex);
};

#endif // GAMEMODEL_H
