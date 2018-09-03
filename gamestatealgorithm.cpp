#include "gamestatealgorithm.h"

GameStateAlgorithm::GameStateAlgorithm()
{

}

GameState GameStateAlgorithm::getState(GameBoard *board, int changedIndex, int cellsToWin)
{
    return GameState::NOTHING;
}

bool GameStateAlgorithm::checkPath(GameBoard *board, BoardIterator *iterator, int cellsToWin)
{
    BoardCell target = board->getCell(iterator->getCurrent());

    // TODO move iterator to the left

    // then move it right
    return false;
}
