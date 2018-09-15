#include "gameboard.h"
#include <algorithm>
#include <QDebug>

GameBoard::GameBoard()
{

}

void GameBoard::newGame(int rows, int cols, int cellsToWin)
{
    m_height = rows;
    m_width = cols;
    m_cellsToWin = cellsToWin;

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

int GameBoard::getCellsToWin() const
{
    return m_cellsToWin;
}

int GameBoard::getIndexCount() const
{
    return static_cast<int>(m_board.size());
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

bool GameBoard::operator==(const GameBoard &other) const
{
    return other.m_cellsToWin == m_cellsToWin
            && other.m_board == m_board
            && other.m_height == m_height
            && other.m_width == m_width;
}

void GameBoard::debugPrint() const
{
    for (int i=0; i<m_height; ++i) {
        QString line;
        for (int j=0; j<m_width; ++j) {
            line += QString::number(getCell(getIndex(i, j)));
            line += " ";
        }
        qDebug() << line;
    }
}
