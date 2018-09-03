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

    HorizontalIterator it(0, 3, 5);
    while (it.hasNext()) {
        int cur = it.getCurrent();
        int next = it.getNext();
        qDebug() << cur << "->" << next;
    }
    while (it.hasPrev()) {
        int cur = it.getCurrent();
        int next = it.getPrev();
        qDebug() << cur << "->" << next;
    }
}
