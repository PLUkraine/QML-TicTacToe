#include "gameopponentenum.h"

void GameOpponentEnum::registerQmlType()
{
    qmlRegisterType<GameOpponentEnum>("TicTacToe", 1, 0, "GameOpponent");
}
