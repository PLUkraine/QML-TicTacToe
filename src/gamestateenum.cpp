#include "gamestateenum.h"
#include <QQmlEngine>

void GameStateClass::registerQmlType() {
    qmlRegisterType<GameStateClass>("TicTacToe", 1, 0, "GameState");
}
