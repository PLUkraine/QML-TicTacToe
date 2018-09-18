#ifndef IGAMEOPPONENT_H
#define IGAMEOPPONENT_H

#include <QObject>

#include "gameboard.h"

class IGameOpponent : public QObject
{
    Q_OBJECT
public:
    explicit IGameOpponent(QObject *parent = nullptr);
    ~IGameOpponent();

    virtual void startComputation(GameBoard *board, bool isXTurn)=0;
    virtual void cancelComputation()=0;

signals:
    void computationEnded(int resultIndex);
};

#endif // IGAMEOPPONENT_H
