#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "opponent/basegameopponent.h"
#include "gameboard.h"
#include "gamestatealgorithm.h"

class GameModel : public QObject {
    Q_OBJECT

private:
    GameStateAlgorithm m_stateAlgo;
    GameBoard m_board;
    std::unique_ptr<BaseGameOpponent> m_opponent;

    bool m_playerXTurn;
    bool m_isActive;
    bool m_isOpponentTurn;

public:
    GameModel(QObject *parent = nullptr);

    // methods
    void startNewGame(int rows, int cols, int cellsToWin);
    void makePlayerMove(int index);
    void makeOpponentMove();

    // getters
    CellStateEnum::EnCellState getCell(int index) const;
    int getIndex(int row, int col) const;
    bool isXTurn() const;
    bool isOpponentTurn() const;

signals:
    void gameIsOver(GameStateClass::EnGameState state);
    void cellChanged(int index, int cellValue);
    void playerChanged(bool isXPlayer);
    void isOpponentTurnChanged(bool isOpponentTurn);

private slots:
    void onMoveSuccess(int index);
    void onOpponentFailure();


private:
    void setNewOpponent(std::unique_ptr<BaseGameOpponent> newOpponent);

    void setOpponentTurn(bool value);
    void flipPlayer();
    void resetPlayer();
    void setCell(int index);
    void computeState(int changedIndex);
};

#endif // GAMEMODEL_H
