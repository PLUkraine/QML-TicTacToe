#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include "cellstateenum.h"

class GameBoard
{
private:
    int m_width;
    int m_height;
    std::vector<CellStateEnum::EnCellState> m_board;

public:
    GameBoard();

    void newGame(int rows, int cols);

    bool hasEmpty() const;

    int getWidth() const;
    int getHeight() const;

    CellStateEnum::EnCellState getCell(int index) const;
    void setCell(int index, CellStateEnum::EnCellState value);

    int getIndex(int row, int col) const;
};

#endif // GAMEBOARD_H
