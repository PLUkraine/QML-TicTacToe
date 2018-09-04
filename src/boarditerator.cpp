#include "boarditerator.h"
#include "assert.h"

BoardIterator::BoardIterator(int curPos, int boardWidth, int boardHeight)
{
    m_width = boardWidth;
    m_height = boardHeight;
    m_pos = curPos;
    m_initValue = curPos;
}

BoardIterator::~BoardIterator()
{
}

int BoardIterator::getCurrent() const
{
    assert(this->isValid(m_pos));
    return m_pos;
}

int BoardIterator::getNext()
{
    m_pos = this->computeNext();
    assert(this->isValid(m_pos));
    return m_pos;
}

bool BoardIterator::hasNext() const
{
    return this->isValid(this->computeNext());
}

int BoardIterator::getPrev()
{
    m_pos = this->computePrev();
    assert(this->isValid(m_pos));
    return m_pos;
}

bool BoardIterator::hasPrev() const
{
    return this->isValid(this->computePrev());
}


HorizontalIterator::HorizontalIterator(int curPos, int boardWidth, int boardHeight)
    : BoardIterator(curPos, boardWidth, boardHeight)
{

}

int HorizontalIterator::computeNext() const
{
    return m_pos + 1;
}

int HorizontalIterator::computePrev() const
{
    return m_pos - 1;
}

bool HorizontalIterator::isValid(int value) const
{
    return value >= 0 && ((value / m_width) == (m_initValue / m_width));
}

VerticalIterator::VerticalIterator(int curPos, int boardWidth, int boardHeight)
    : BoardIterator(curPos, boardWidth, boardHeight)
{

}

int VerticalIterator::computeNext() const
{
    return m_pos + m_width;
}

int VerticalIterator::computePrev() const
{
    return m_pos - m_width;
}

bool VerticalIterator::isValid(int value) const
{
    return value >= 0 && value < m_width * m_height;
}

MainDiagonalIterator::MainDiagonalIterator(int curPos, int boardWidth, int boardHeight)
    : BoardIterator(curPos, boardWidth, boardHeight)
{

}

int MainDiagonalIterator::computeNext() const
{
    return m_pos + m_width + 1;
}

int MainDiagonalIterator::computePrev() const
{
    return m_pos - m_width - 1;
}

bool MainDiagonalIterator::isValid(int value) const
{
    int deltaX = (value / m_width) - (m_initValue / m_width);
    int deltaY = (value % m_width) - (m_initValue % m_width);
    return value >= 0 && value < m_width * m_height
            && deltaX == deltaY;
}

AlternativeDiagonalIterator::AlternativeDiagonalIterator(int curPos, int boardWidth, int boardHeight)
    : BoardIterator(curPos, boardWidth, boardHeight)
{

}

int AlternativeDiagonalIterator::computeNext() const
{
    return m_pos + m_width - 1;
}

int AlternativeDiagonalIterator::computePrev() const
{
    return m_pos - m_width + 1;
}

bool AlternativeDiagonalIterator::isValid(int value) const
{
    int deltaX = (value / m_width) - (m_initValue / m_width);
    int deltaY = (m_initValue % m_width) - (value % m_width);
    return value >= 0 && value < m_width * m_height
            && deltaX == deltaY;
}
