#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include "gamemodel.h"

class GameController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isXTurn READ isXTurn NOTIFY playerChanged)

private:
    GameModel m_model;
public:
    static void registerQmlType();
    explicit GameController(QObject *parent = nullptr);

    bool isXTurn() const;


    // TODO delete
    Q_INVOKABLE void newGame(int rows, int cols, int cellsToWin);
    Q_INVOKABLE void makeMove(int row, int col);

signals:
    void playerChanged(bool isXPlayer);
    void gameIsOver(int result);
    void cellChanged(int row, int col, int newState);
};

#endif // GAMECONTROLLER_H
