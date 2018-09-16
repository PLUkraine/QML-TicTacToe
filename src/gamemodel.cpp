#include "gamemodel.h"



GameModel::GameModel(QObject *parent)
    : QObject(parent)
{
    m_isActive = false;
}

void GameModel::startNewGame(int rows, int cols, int cellsToWin)
{
    m_isActive = true;
    m_board.newGame(rows, cols, cellsToWin);
    resetPlayer();
}

GameStateClass::EnGameState GameModel::makePlayerMove(int index)
{
    assert(m_isActive);

    setCell(index);
    flipPlayer();
    return computeState(index);
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

GameStateClass::EnGameState GameModel::computeState(int changedIndex)
{
    auto answer = m_stateAlgo.getState(&m_board, changedIndex);
    if (answer != GameStateClass::STATE_NOTHING) {
        m_isActive = false;
    }
    return answer;
}

CellStateEnum::EnCellState GameModel::getCell(int index) const
{
    return m_board.getCell(index);
}

int GameModel::getIndex(int row, int col) const
{
    return m_board.getIndex(row, col);
}
