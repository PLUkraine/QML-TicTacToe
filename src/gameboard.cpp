#include "gameboard.h"
#include <algorithm>

GameBoard::GameBoard()
{

}

void GameBoard::newGame(int rows, int cols)
{
    m_height = rows;
    m_width = cols;

    m_board.assign(static_cast<std::size_t>(rows*cols), CellStateEnum::EnCellState::EMPTY);
}

bool GameBoard::hasEmpty() const
{
    return std::any_of(m_board.begin(), m_board.end(), [](CellStateEnum::EnCellState element) {
        return element == CellStateEnum::EnCellState::EMPTY;
    });
}

int GameBoard::getWidth() const
{
    return m_width;
}

int GameBoard::getHeight() const
{
    return m_height;
}

CellStateEnum::EnCellState GameBoard::getCell(int index) const
{
    return m_board[static_cast<std::size_t>(index)];
}

void GameBoard::setCell(int index, CellStateEnum::EnCellState value)
{
    m_board[static_cast<std::size_t>(index)] = value;
}

int GameBoard::getIndex(int row, int col) const
{
    return row * m_width + col;
}
