#ifndef BASEGAMEOPPONENT_H
#define BASEGAMEOPPONENT_H

#include <QObject>
#include "gameboard.h"

class BaseGameOpponent : public QObject
{
    Q_OBJECT
public:
    explicit BaseGameOpponent(QObject *parent = nullptr);

    virtual void queryMove(GameBoard *model, bool isXTurn)=0;
    virtual void endGame(GameBoard *model)=0;

signals:
    void moveSuccess(int index);
    void moveFailed();
};

#endif // BASEGAMEOPPONENT_H
