#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "gamecontroller.h"
#include "enums/gamestateenum.h"
#include "enums/cellstateenum.h"
#include "enums/gameopponentenum.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // register QML plugins
    GameController::registerQmlType();
    GameStateClass::registerQmlType();
    CellStateEnum::registerQmlType();
    GameOpponentEnum::registerQmlType();


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
