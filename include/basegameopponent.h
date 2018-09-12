#ifndef BASEGAMEOPPONENT_H
#define BASEGAMEOPPONENT_H

#include <QObject>

class BaseGameOpponent : public QObject
{
    Q_OBJECT
public:
    explicit BaseGameOpponent(QObject *parent = nullptr);

signals:
};

#endif // BASEGAMEOPPONENT_H
