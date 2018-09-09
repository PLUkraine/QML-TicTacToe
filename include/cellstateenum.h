#ifndef CELLSTATEENUM_H
#define CELLSTATEENUM_H

#include <QQmlEngine>

class CellStateEnum : public QObject
{
    Q_OBJECT
public:
    CellStateEnum() : QObject() {}

    enum EnCellState
    {
        EMPTY,
        X,
        O
    };
    Q_ENUMS(EnCellState)

    // Do not forget to declare your class to the QML system.
    static void registerQmlType();
};

#endif // CELLSTATEENUM_H
