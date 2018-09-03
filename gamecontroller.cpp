#include "gamecontroller.h"
#include <QDebug>
#include <QQmlApplicationEngine>
#include "boarditerator.h"

void GameController::registerQmlType()
{
    qmlRegisterType<GameController>("TicTacToe", 1, 0, "GameController");
}

GameController::GameController(QObject *parent) : QObject(parent)
{
    // TODO initialization of the object
}

void GameController::sayHello()
{
    qDebug() << "Hello, World!";

    int cur = 2;
    AlternativeDiagonalIterator it(cur, 3, 5);
    while (it.hasNext()) {
        int nxt = it.getNext();
        qDebug() << cur << "->" << nxt;
        cur = nxt;
    }
    while (it.hasPrev()) {
        int nxt = it.getPrev();
        qDebug() << cur << "->" << nxt;
        cur = nxt;
    }
}
