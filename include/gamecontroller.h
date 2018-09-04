#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>

class GameController : public QObject
{
    Q_OBJECT
public:
    static void registerQmlType();

    explicit GameController(QObject *parent = nullptr);

    // TODO delete
    Q_INVOKABLE void sayHello();

signals:

public slots:
};

#endif // GAMECONTROLLER_H
