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
    Q_INVOKABLE void makeMove(int index);
    Q_INVOKABLE int getIndex(int row, int col) const;

signals:
    void playerChanged(bool isXPlayer);
    void gameIsOver(int result);
    void cellChanged(int index, int newState);
};

#endif // GAMECONTROLLER_H
