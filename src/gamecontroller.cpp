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
    m_navigator.resetDimensions(rows, cols);
    playerChanged(m_model.isXTurn());
}

void GameController::makeMove(int index)
{
    auto newState = m_model.makeMove(index);
    emit cellChanged(index, m_model.getCell(index));
    postMoveChecks(newState);

    // TODO if (opponent)
}

int GameController::getIndex(int row, int col) const
{
    return m_model.getIndex(row, col);
}

int GameController::navigateTo(int index, Qt::Key keyboardInput) const
{
    return m_navigator.navigateTo(index, keyboardInput);
}

void GameController::postMoveChecks(GameStateClass::EnGameState newState) {
    if (newState != GameStateClass::STATE_NOTHING) {
        emit gameIsOver(static_cast<int>(newState));
    }
    else {
        emit playerChanged(m_model.isXTurn());
    }
}
