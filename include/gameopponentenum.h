#ifndef GAMEOPPONENTENUM_H
#define GAMEOPPONENTENUM_H

#include <QObject>

class GameOpponentEnum : public QObject
{
    Q_OBJECT
public:
    GameOpponentEnum() : QObject() {}

    enum EnGameOpponent
    {
        NONE,
        CPU
    };
    Q_ENUMS(EnGameOpponent)

    // Do not forget to declare your class to the QML system.
    static void registerQmlType();
};

#endif // GAMEOPPONENTENUM_H
