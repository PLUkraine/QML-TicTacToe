#include "gameboard.h"

GameBoard::GameBoard()
{

}

void GameBoard::newGame(int rows, int cols)
{
    m_height = rows;
    m_width = cols;

    m_board.assign(static_cast<std::size_t>(rows*cols), BoardCell::Empty);
}

int GameBoard::getWidth() const
{
    return m_width;
}

int GameBoard::getHeight() const
{
    return m_height;
}

BoardCell GameBoard::getCell(int index) const
{
    return m_board[static_cast<std::size_t>(index)];
}

void GameBoard::setCell(int index, BoardCell value)
{
    m_board[static_cast<std::size_t>(index)] = value;
}

int GameBoard::getIndex(int row, int col) const
{
    return row * m_width + col;
}
