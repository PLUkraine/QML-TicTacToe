#include "keyboardnavigator.h"


void KeyboardNavigator::resetDimensions(int rows, int cols)
{
    m_rows = rows;
    m_cols = cols;
}

int KeyboardNavigator::navigateTo(int indexFrom, Qt::Key keyboardInput) const
{
    auto params = mapKeyToIter(indexFrom, keyboardInput);
    if (!params.first) return indexFrom;

    if (params.second) {
        return params.first->hasNext() ? params.first->getNext() : indexFrom;
    } else {
        return params.first->hasPrev() ? params.first->getPrev() : indexFrom;
    }
}

std::pair<std::unique_ptr<BoardIterator>, bool> KeyboardNavigator::mapKeyToIter(int pos, Qt::Key keyboardInput) const
{
    if (keyboardInput == Qt::Key_Left) {
        return std::make_pair(
                    std::unique_ptr<BoardIterator>(new HorizontalIterator(pos, m_cols, m_rows)),
                    false
                    );
    }
    if (keyboardInput == Qt::Key_Right) {
        return std::make_pair(
                    std::unique_ptr<BoardIterator>(new HorizontalIterator(pos, m_cols, m_rows)),
                    true
                    );
    }
    if (keyboardInput == Qt::Key_Down) {
        return std::make_pair(
                    std::unique_ptr<BoardIterator>(new VerticalIterator(pos, m_cols, m_rows)),
                    true
                    );
    }
    if (keyboardInput == Qt::Key_Up) {
        return std::make_pair(
                    std::unique_ptr<BoardIterator>(new VerticalIterator(pos, m_cols, m_rows)),
                    false
                    );
    }
    return {nullptr, false};
}
