#include <QTest>
#include <memory>

#include "perfectai.h"
#include "boarditerator.h"

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

        PerfectAi ai;
        int index = ai.startBlockingComputation(&board, true);
        QCOMPARE(index, 2);

        index = ai.startBlockingComputation(&board, false);
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

        PerfectAi ai;
        int index = ai.startBlockingComputation(&board, true);
        QCOMPARE(index, 2);

        index = ai.startBlockingComputation(&board, false);
        QCOMPARE(index, 2);
    }
    void testPerfectAi3() {
        GameBoard board;
        board.newGame(3, 3, 3);
        board.setCell(0, CellStateEnum::X);
        board.setCell(1, CellStateEnum::O);
        board.setCell(2, CellStateEnum::EMPTY);

        board.setCell(3, CellStateEnum::EMPTY);
        board.setCell(4, CellStateEnum::X);
        board.setCell(5, CellStateEnum::EMPTY);
        board.debugPrint();

        std::unique_ptr<PerfectAi> ai(new PerfectAi());
        int index = ai->startBlockingComputation(&board, false);
        QCOMPARE(index, 8);

        index = ai->startBlockingComputation(&board, true);
        QCOMPARE(index, 2);
    }
};

QTEST_MAIN(BoardIteratorTest)
#include "BoardIteratorTest.moc"
