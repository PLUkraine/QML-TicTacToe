#include "cellstateenum.h"

void CellStateEnum::registerQmlType()
{
    qmlRegisterType<CellStateEnum>("TicTacToe", 1, 0, "CellState");
}
