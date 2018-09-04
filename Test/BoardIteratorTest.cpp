#include <QTest>
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
};

QTEST_MAIN(BoardIteratorTest)
#include "BoardIteratorTest.moc"
