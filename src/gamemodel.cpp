#include "gamemodel.h"
#include <QDebug>

#include "opponents/perfectai.h"




GameModel::GameModel(QObject *parent)
    : QObject(parent)
{
    this->setAi(false);
    m_canPlayerMove = false;
    m_isGameActive = false;
}

void GameModel::startNewGame(int rows, int cols, int cellsToWin, GameOpponentEnum::EnGameOpponent opponent)
{
    m_isGameActive = true;
    m_canPlayerMove = true;

    setAi(opponent == GameOpponentEnum::CPU);
    m_board.newGame(rows, cols, cellsToWin);
    resetPlayer();
}

void GameModel::makePlayerMove(int index)
{
    assert(m_isGameActive);
    if (!m_canPlayerMove) {
        qWarning() << "Trying to move player when model is not active!";
        return;
    }

    setCell(index);
    flipPlayer();
    computeState(index);

    if (!m_isGameActive || m_ai.isNull()) return;
    m_canPlayerMove = false;
    m_ai->startComputation(&m_board, isXTurn());
}

bool GameModel::isXTurn() const
{
    assert(m_isGameActive);
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
        m_canPlayerMove = false;
        m_isGameActive = false;
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

void GameModel::setAi(bool value)
{
    if ((!value && m_ai.isNull()) || (value && !m_ai.isNull())) return;

    if (value) {
        m_ai = new PerfectAi(this);
        connect(m_ai, &IGameOpponent::computationEnded, this, &GameModel::onComputationEnded);
    } else {
        m_ai->cancelComputation();
        m_ai->deleteLater();
        m_ai = nullptr;
    }
}

void GameModel::onComputationEnded(int index)
{
    m_canPlayerMove = true;
    setCell(index);
    flipPlayer();
    computeState(index);
}


