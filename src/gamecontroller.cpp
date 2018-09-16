#include "gamecontroller.h"
#include <QDebug>
#include <QQmlApplicationEngine>
#include "gamestatealgorithm.h"

void GameController::registerQmlType()
{
    qmlRegisterType<GameController>("TicTacToe", 1, 0, "GameController");
}

GameController::GameController(QObject *parent)
    : QObject(parent),
      m_model(new GameModel(this))
{
    connect(m_model, &GameModel::cellChanged, this, &GameController::cellChanged);
    connect(m_model, &GameModel::playerChanged, this, &GameController::playerChanged);
}

bool GameController::isXTurn() const
{
    return m_model->isXTurn();
}

void GameController::newGame(int rows, int cols, int cellsToWin, int gameOpponent)
{
    m_model->startNewGame(rows, cols, cellsToWin);
    m_navigator.resetDimensions(rows, cols);
}

void GameController::makeMove(int index)
{
    auto newState = m_model->makePlayerMove(index);
    postMoveChecks(newState);

    // TODO if (opponent)
}

int GameController::getIndex(int row, int col) const
{
    return m_model->getIndex(row, col);
}

int GameController::navigateTo(int index, Qt::Key keyboardInput) const
{
    return m_navigator.navigateTo(index, keyboardInput);
}

void GameController::postMoveChecks(GameStateClass::EnGameState newState) {
    if (newState != GameStateClass::STATE_NOTHING) {
        emit gameIsOver(static_cast<int>(newState));
    }
}
