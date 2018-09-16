#ifndef BASEGAMEOPPONENT_H
#define BASEGAMEOPPONENT_H

#include <QObject>

class BaseGameOpponent : public QObject
{
    Q_OBJECT
public:
    explicit BaseGameOpponent(QObject *parent = nullptr);

    virtual void queryMove(/*TODO pass board here*/)=0;

signals:
    void moveSuccess();
    void moveFailed();
};

#endif // BASEGAMEOPPONENT_H
