#include "gameopponentenum.h"
#include <QQmlEngine>

void GameOpponentEnum::registerQmlType()
{
    qmlRegisterType<GameOpponentEnum>("TicTacToe", 1, 0, "GameOpponent");
}
