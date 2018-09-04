#ifndef GAMESTATEENUM_H
#define GAMESTATEENUM_H

#include <QQmlEngine>

class GameStateClass : public QObject
{
    Q_OBJECT
public:
    GameStateClass() : QObject() {}

    enum EnGameState
    {
        STATE_NOTHING,
        STATE_DRAW,
        STATE_X_WIN,
        STATE_O_WIN
    };
    Q_ENUMS(EnGameState)

    // Do not forget to declare your class to the QML system.
    static void registerQmlType();
};

#endif // GAMESTATEENUM_H
