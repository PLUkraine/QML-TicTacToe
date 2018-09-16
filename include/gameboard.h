#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include "enums/cellstateenum.h"

class GameBoard
{
private:
    int m_width;
    int m_height;
    int m_cellsToWin;
    std::vector<CellStateEnum::EnCellState> m_board;

public:
    GameBoard();

    void newGame(int rows, int cols, int cellsToWin);

    bool hasEmpty() const;

    int getWidth() const;
    int getHeight() const;
    int getCellsToWin() const;
    int getIndexCount() const;

    CellStateEnum::EnCellState getCell(int index) const;
    void setCell(int index, CellStateEnum::EnCellState value);

    int getIndex(int row, int col) const;

    bool operator==(const GameBoard& other) const;

    void debugPrint() const;
};

#endif // GAMEBOARD_H
