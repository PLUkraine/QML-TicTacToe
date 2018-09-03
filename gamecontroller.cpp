#include "gamecontroller.h"
#include <QDebug>
#include <QQmlApplicationEngine>

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
}
