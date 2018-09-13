#ifndef KEYBOARDNAVIGATOR_H
#define KEYBOARDNAVIGATOR_H

#include <Qt>
#include <memory>
#include "boarditerator.h"


class KeyboardNavigator
{
private:
    int m_cols;
    int m_rows;

public:
    void resetDimensions(int rows, int cols);
    int navigateTo(int indexFrom, Qt::Key keyboardInput) const;

private:
    std::pair<std::unique_ptr<BoardIterator>, bool> mapKeyToIter(int pos, Qt::Key keyboardInput) const;
};

#endif // KEYBOARDNAVIGATOR_H
