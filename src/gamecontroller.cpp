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
}

bool GameController::isXTurn() const
{
    return m_model.isXTurn();
}

void GameController::newGame(int rows, int cols, int cellsToWin)
{
    m_model.startNewGame(rows, cols, cellsToWin);
}

void GameController::makeMove(int row, int col)
{
    auto newState = m_model.makeMove(row, col);
    emit cellChanged(row, col, m_model.getCell(row, col));

    if (newState != GameStateClass::STATE_NOTHING) {
        emit gameIsOver(static_cast<int>(newState));
    }
    else {
        emit playerChanged(m_model.isXTurn());
    }
}
