#ifndef IBOARDITERATOR_H
#define IBOARDITERATOR_H


class BoardIterator
{
protected:
    int m_width;
    int m_height;
    int m_pos;
    int m_initValue;
public:
    BoardIterator(int curPos, int boardWidth, int boardHeight);
    virtual ~BoardIterator();

    int getCurrent() const;

    int getNext();
    bool hasNext() const;

    int getPrev();
    bool hasPrev() const;

private:
    virtual int computeNext() const = 0;
    virtual int computePrev() const = 0;
    virtual bool isValid(int value) const = 0;
};

class HorizontalIterator : public BoardIterator {
public:
    HorizontalIterator(int curPos, int boardWidth, int boardHeight);
private:
    virtual int computeNext() const override;
    virtual int computePrev() const override;
    virtual bool isValid(int value) const override;
};

class VerticalIterator : public BoardIterator {
public:
    VerticalIterator(int curPos, int boardWidth, int boardHeight);
private:
    virtual int computeNext() const override;
    virtual int computePrev() const override;
    virtual bool isValid(int value) const override;
};

class MainDiagonalIterator : public BoardIterator {
public:
    MainDiagonalIterator(int curPos, int boardWidth, int boardHeight);
private:
    virtual int computeNext() const override;
    virtual int computePrev() const override;
    virtual bool isValid(int value) const override;
};

class AlternativeDiagonalIterator : public BoardIterator {
public:
    AlternativeDiagonalIterator(int curPos, int boardWidth, int boardHeight);
private:
    virtual int computeNext() const override;
    virtual int computePrev() const override;
    virtual bool isValid(int value) const override;
};

#endif // IBOARDITERATOR_H
