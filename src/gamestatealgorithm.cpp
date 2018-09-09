#include "gamestatealgorithm.h"

GameStateAlgorithm::GameStateAlgorithm()
{

}

GameStateClass::EnGameState GameStateAlgorithm::getState(GameBoard *board, int changedIndex, int cellsToWin)
{
    HorizontalIterator hIt(changedIndex, board->getWidth(), board->getHeight());
    if (checkPath(board, &hIt, cellsToWin)) {
        return determineWinner(board, changedIndex);
    }
    VerticalIterator vIt(changedIndex, board->getWidth(), board->getHeight());
    if (checkPath(board, &vIt, cellsToWin)) {
        return determineWinner(board, changedIndex);
    }
    MainDiagonalIterator dIt(changedIndex, board->getWidth(), board->getHeight());
    if (checkPath(board, &dIt, cellsToWin)) {
        return determineWinner(board, changedIndex);
    }
    AlternativeDiagonalIterator adIt(changedIndex, board->getWidth(), board->getHeight());
    if (checkPath(board, &adIt, cellsToWin)) {
        return determineWinner(board, changedIndex);
    }

    return board->hasEmpty() ? GameStateClass::STATE_NOTHING : GameStateClass::STATE_DRAW;
}

bool GameStateAlgorithm::checkPath(GameBoard *board, BoardIterator *iterator, int cellsToWin)
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

GameStateClass::EnGameState GameStateAlgorithm::determineWinner(GameBoard *board, int pos)
{
    return board->getCell(pos) == CellStateEnum::EnCellState::X
            ? GameStateClass::STATE_X_WIN
            : GameStateClass::STATE_O_WIN;
}
