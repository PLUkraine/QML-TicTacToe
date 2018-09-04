#include "gamecontroller.h"
#include <QDebug>
#include <QQmlApplicationEngine>
#include "gamestatealgorithm.h"

void GameController::registerQmlType()
{
    qmlRegisterType<GameController>("TicTacToe", 1, 0, "GameController");
}

GameController::GameController(QObject *parent) : QObject(parent)
{
    // TODO initialization of the object
}

void GameController::sayHello()
{
    qDebug() << "Hello, World!";

    GameBoard board;
    board.newGame(3, 3);

    board.setCell(board.getIndex(0, 0), BoardCell::X);
    board.setCell(board.getIndex(0, 1), BoardCell::O);
    board.setCell(board.getIndex(0, 2), BoardCell::X);
    board.setCell(board.getIndex(1, 0), BoardCell::X);
    board.setCell(board.getIndex(1, 1), BoardCell::X);
    board.setCell(board.getIndex(1, 2), BoardCell::O);
    board.setCell(board.getIndex(2, 0), BoardCell::O);
    board.setCell(board.getIndex(2, 1), BoardCell::X);
    board.setCell(board.getIndex(2, 2), BoardCell::O);

    GameStateAlgorithm algo;
    qDebug() << static_cast<int>(algo.getState(&board, board.getIndex(2, 1), 3));


//    HorizontalIterator it(0, 3, 5);
//    while (it.hasNext()) {
//        int cur = it.getCurrent();
//        int next = it.getNext();
//        qDebug() << cur << "->" << next;
//    }
//    while (it.hasPrev()) {
//        int cur = it.getCurrent();
//        int next = it.getPrev();
//        qDebug() << cur << "->" << next;
//    }
}
