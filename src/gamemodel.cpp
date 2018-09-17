#include "gamemodel.h"
#include <QDebug>
#include "opponent/cpuopponent.h"



GameModel::GameModel(QObject *parent)
    : QObject(parent)
{
    m_isActive = false;
    m_isOpponentTurn = false;
}

void GameModel::startNewGame(int rows, int cols, int cellsToWin)
{
    m_isActive = true;
    m_board.newGame(rows, cols, cellsToWin);
    resetPlayer();

    setOpponentTurn(false);
    setNewOpponent(std::unique_ptr<BaseGameOpponent>(new CpuOpponent(false, this)));
}

void GameModel::makePlayerMove(int index)
{
    if (!m_isActive || m_isOpponentTurn) {
        qWarning() << "Trying to move player when model is not active!";
        return;
    }

    setCell(index);
    flipPlayer();
    computeState(index);
}

void GameModel::makeOpponentMove()
{
    // stub
    if (!m_isActive || m_isOpponentTurn) {
        qWarning() << "Trying to move opponent when model is not active!";
        return;
    }

    if (!m_opponent) return;
    setOpponentTurn(true);
    m_opponent->queryMove(&m_board, isXTurn());
}

void GameModel::setOpponentTurn(bool value) {
    if (m_isOpponentTurn == value) {
        qWarning() << "Setting same value" << value << "for m_isOpponentTurn";
        return;
    }
    m_isOpponentTurn = value;
    emit isOpponentTurnChanged(m_isOpponentTurn);
}

bool GameModel::isXTurn() const
{
    assert(m_isActive);
    return m_playerXTurn;
}

bool GameModel::isOpponentTurn() const
{
    return m_isOpponentTurn;
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
        m_opponent->endGame(&m_board);
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

void GameModel::onMoveSuccess(int index)
{
    setOpponentTurn(false);
    setCell(index);
    flipPlayer();
    computeState(index);
}
void GameModel::onOpponentFailure()
{
    qCritical() << "Opponent failed to deliver an answer!";
    exit(1);
}

void GameModel::setNewOpponent(std::unique_ptr<BaseGameOpponent> newOpponent)
{
    if (m_opponent) {
        disconnect(m_opponent.get(), &BaseGameOpponent::moveSuccess, this, &GameModel::onMoveSuccess);
        disconnect(m_opponent.get(), &BaseGameOpponent::moveFailed, this, &GameModel::onOpponentFailure);
    }

    assert(newOpponent.get());
    m_opponent = std::move(newOpponent);
    connect(m_opponent.get(), &BaseGameOpponent::moveSuccess, this, &GameModel::onMoveSuccess);
    connect(m_opponent.get(), &BaseGameOpponent::moveFailed, this, &GameModel::onOpponentFailure);
}
