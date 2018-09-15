#include "gamestatealgorithm.h"

GameStateAlgorithm::GameStateAlgorithm()
{

}

GameStateClass::EnGameState GameStateAlgorithm::getState(GameBoard const *board, int changedIndex) const
{
    HorizontalIterator hIt(changedIndex, board->getWidth(), board->getHeight());
    if (checkPath(board, &hIt, board->getCellsToWin())) {
        return determineWinner(board, changedIndex);
    }
    VerticalIterator vIt(changedIndex, board->getWidth(), board->getHeight());
    if (checkPath(board, &vIt, board->getCellsToWin())) {
        return determineWinner(board, changedIndex);
    }
    MainDiagonalIterator dIt(changedIndex, board->getWidth(), board->getHeight());
    if (checkPath(board, &dIt, board->getCellsToWin())) {
        return determineWinner(board, changedIndex);
    }
    AlternativeDiagonalIterator adIt(changedIndex, board->getWidth(), board->getHeight());
    if (checkPath(board, &adIt, board->getCellsToWin())) {
        return determineWinner(board, changedIndex);
    }

    return board->hasEmpty() ? GameStateClass::STATE_NOTHING : GameStateClass::STATE_DRAW;
}

CellStateEnum::EnCellState GameStateAlgorithm::changePlayer(CellStateEnum::EnCellState curPlayer) const
{
    return curPlayer == CellStateEnum::X ? CellStateEnum::O : CellStateEnum::X;
}

bool GameStateAlgorithm::checkPath(GameBoard const *board, BoardIterator *iterator, int cellsToWin) const
{
    CellStateEnum::EnCellState target = board->getCell(iterator->getCurrent());

    // move iterator to the left (until item under
    // the iterator is same)
    while (board->getCell(iterator->getCurrent()) == target && iterator->hasPrev()) {
        iterator->getPrev();
    }
    // if we went too far, get on the track again
    if (board->getCell(iterator->getCurrent()) != target) {
        iterator->getNext();
    }

    // move iterator to the right. if we encountered exactly
    // cellsToWin same cells, we win!
    while (board->getCell(iterator->getCurrent()) == target
           && --cellsToWin > 0 && iterator->hasNext()) {
        iterator->getNext();
    }

    return cellsToWin == 0;
}

GameStateClass::EnGameState GameStateAlgorithm::determineWinner(GameBoard const *board, int pos) const
{
    return board->getCell(pos) == CellStateEnum::EnCellState::X
            ? GameStateClass::STATE_X_WIN
            : GameStateClass::STATE_O_WIN;
}
