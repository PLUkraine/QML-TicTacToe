#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>

enum class BoardCell: char {
    Empty, X, O
};

class GameBoard
{
private:
    int m_width;
    int m_height;
    std::vector<BoardCell> m_board;

public:
    GameBoard();

    void newGame(int rows, int cols);

    int getWidth() const;
    int getHeight() const;

    BoardCell getCell(int index) const;
    void setCell(int index, BoardCell value);

    int getIndex(int row, int col) const;
};

#endif // GAMEBOARD_H
