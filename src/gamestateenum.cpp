#include "gamestateenum.h"

void GameStateClass::registerQmlType() {
    qmlRegisterType<GameStateClass>("TicTacToe", 1, 0, "GameState");
}
