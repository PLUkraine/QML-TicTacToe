#include "gamemodel.h"



GameModel::GameModel()
{
    m_isActive = false;
}

void GameModel::startNewGame(int rows, int cols, int cellsToWin)
{
    m_isActive = true;
    m_board.newGame(rows, cols, cellsToWin);
    m_playerXTurn = true;
}

GameStateClass::EnGameState GameModel::makePlayerMove(int index)
{
    assert(m_isActive);

    m_board.setCell(index,
                    m_playerXTurn
                        ? CellStateEnum::EnCellState::X
                        : CellStateEnum::EnCellState::O);
    m_playerXTurn = !m_playerXTurn;

    auto answer = m_stateAlgo.getState(&m_board, index);
    if (answer != GameStateClass::STATE_NOTHING) {
        m_isActive = false;
    }
    return answer;
}


bool GameModel::isXTurn() const
{
    assert(m_isActive);
    return m_playerXTurn;
}

CellStateEnum::EnCellState GameModel::getCell(int index) const
{
    return m_board.getCell(index);
}

int GameModel::getIndex(int row, int col) const
{
    return m_board.getIndex(row, col);
}
