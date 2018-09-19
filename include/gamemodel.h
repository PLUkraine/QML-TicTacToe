#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QPointer>

#include "gameboard.h"
#include "gamestatealgorithm.h"
#include "enums/gameopponentenum.h"
#include "opponents/igameopponent.h"

class GameModel : public QObject {
    Q_OBJECT

private:
    GameStateAlgorithm m_stateAlgo;
    GameBoard m_board;
    QPointer<IGameOpponent> m_ai;

    bool m_playerXTurn;
    bool m_canPlayerMove;
    bool m_isGameActive;

public:
    GameModel(QObject *parent = nullptr);

    // methods
    void startNewGame(int rows, int cols, int cellsToWin, GameOpponentEnum::EnGameOpponent opponent);
    void makePlayerMove(int index);

    // getters
    CellStateEnum::EnCellState getCell(int index) const;
    int getIndex(int row, int col) const;
    bool isXTurn() const;

signals:
    void gameIsOver(GameStateClass::EnGameState state);
    void cellChanged(int index, int cellValue);
    void playerChanged(bool isXPlayer);

private:
    void setAi(bool value);

    void flipPlayer();
    void resetPlayer();
    void setCell(int index);
    void computeState(int changedIndex);

private slots:
    void onComputationEnded(int index);
};

#endif // GAMEMODEL_H
