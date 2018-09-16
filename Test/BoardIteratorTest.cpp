#include <QTest>

#include "boarditerator.h"
#include "opponent/perfectgameai.h"

class BoardIteratorTest : public QObject {
    Q_OBJECT
private slots:
    void testHorizontalIterator() {
        HorizontalIterator it(4, 3, 3);
        QVERIFY(it.hasNext());
        QVERIFY(it.getNext() == 5);

        QVERIFY(!it.hasNext());

        QVERIFY(it.hasPrev());
        QVERIFY(it.getPrev() == 4);

        QVERIFY(it.hasPrev());
        QVERIFY(it.getPrev() == 3);

        QVERIFY(!it.hasPrev());
    }

    void testPerfectAi1() {

        GameBoard board;
        board.newGame(3, 3, 3);
        board.setCell(0, CellStateEnum::X);
        board.setCell(1, CellStateEnum::X);
        board.setCell(2, CellStateEnum::EMPTY);

        board.setCell(3, CellStateEnum::O);
        board.setCell(4, CellStateEnum::O);
        board.setCell(5, CellStateEnum::EMPTY);

        board.setCell(6, CellStateEnum::X);
        board.setCell(7, CellStateEnum::O);
        board.setCell(8, CellStateEnum::EMPTY);
        board.debugPrint();

        PerfectGameAi ai;
        int index = ai.makeMove(&board, true, true);
        QCOMPARE(index, 2);

        index = ai.makeMove(&board, false, false);
        QCOMPARE(index, 5);
    }
    void testPerfectAi2() {
        GameBoard board;
        board.newGame(3, 3, 3);
        board.setCell(0, CellStateEnum::X);
        board.setCell(1, CellStateEnum::X);
        board.setCell(2, CellStateEnum::EMPTY);

        board.setCell(3, CellStateEnum::O);
        board.setCell(4, CellStateEnum::O);
        board.setCell(5, CellStateEnum::EMPTY);

        board.setCell(6, CellStateEnum::EMPTY);
        board.setCell(7, CellStateEnum::EMPTY);
        board.setCell(8, CellStateEnum::EMPTY);
        board.debugPrint();

        PerfectGameAi ai;
        int index = ai.makeMove(&board, true, true);
        QCOMPARE(index, 2);

        index = ai.makeMove(&board, false, false);
        QCOMPARE(index, 2);
    }
};

QTEST_MAIN(BoardIteratorTest)
#include "BoardIteratorTest.moc"
