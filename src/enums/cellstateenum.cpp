#include "enums/cellstateenum.h"
#include <QQmlEngine>


void CellStateEnum::registerQmlType()
{
    qmlRegisterType<CellStateEnum>("TicTacToe", 1, 0, "CellState");
}
