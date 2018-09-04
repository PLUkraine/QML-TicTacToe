#include "gamemodel.h"



GameModel::GameModel()
{
    m_isActive = false;
}

void GameModel::startNewGame(int rows, int cols, int cellsToWin)
{
    m_isActive = true;
    m_board.newGame(rows, cols);
    m_cellsToWin = cellsToWin;
    m_playerXTurn = true;
}

GameStateClass::EnGameState GameModel::makeMove(int row, int col)
{
    assert(m_isActive);

    m_board.setCell(m_board.getIndex(row, col), m_playerXTurn ? BoardCell::X : BoardCell::O);
    m_playerXTurn = !m_playerXTurn;

    auto answer = m_stateAlgo.getState(&m_board, m_board.getIndex(row, col), m_cellsToWin);
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
