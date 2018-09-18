#include "gamemodel.h"
#include <QDebug>



GameModel::GameModel(QObject *parent)
    : QObject(parent)
{
    this->setAi();
    m_isActive = false;
}

void GameModel::startNewGame(int rows, int cols, int cellsToWin)
{
    m_ai->cancelComputation();
    m_isActive = true;
    m_board.newGame(rows, cols, cellsToWin);
    resetPlayer();
}

void GameModel::makePlayerMove(int index)
{
    if (!m_isActive) {
        qWarning() << "Trying to move player when model is not active!";
        return;
    }

    setCell(index);
    flipPlayer();
    computeState(index);

    if (!m_isActive) return;

    m_isActive = false;
    m_ai->startComputation(&m_board, isXTurn());
}

bool GameModel::isXTurn() const
{
    assert(m_isActive);
    return m_playerXTurn;
}


void GameModel::flipPlayer()
{
    m_playerXTurn = !m_playerXTurn;
    emit playerChanged(m_playerXTurn);
}

void GameModel::resetPlayer()
{
    m_playerXTurn = true;
    emit playerChanged(m_playerXTurn);
}

void GameModel::setCell(int index)
{
    CellStateEnum::EnCellState state = m_playerXTurn
            ? CellStateEnum::EnCellState::X
            : CellStateEnum::EnCellState::O;

    m_board.setCell(index,state);
    emit cellChanged(index, state);
}

void GameModel::computeState(int changedIndex)
{
    auto answer = m_stateAlgo.getState(&m_board, changedIndex);
    if (answer != GameStateClass::STATE_NOTHING) {
        m_isActive = false;
        emit gameIsOver(answer);
    }
}

CellStateEnum::EnCellState GameModel::getCell(int index) const
{
    return m_board.getCell(index);
}

int GameModel::getIndex(int row, int col) const
{
    return m_board.getIndex(row, col);
}

void GameModel::setAi()
{
    if (m_ai) {
        m_ai->cancelComputation();
        m_ai->deleteLater();
    }

    m_ai = new PerfectAi(this);
    connect(m_ai, &PerfectAi::computationEnded, this, &GameModel::onComputationEnded);
}

void GameModel::onComputationEnded(int index)
{
    m_isActive = true;
    setCell(index);
    flipPlayer();
    computeState(index);
}


