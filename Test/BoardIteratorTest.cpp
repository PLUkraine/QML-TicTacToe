#include <QTest>
#include "boarditerator.h"

class BoardIteratorTest : public QObject {
    Q_OBJECT
private slots:
    void testHorizontalIterator() {
        HorizontalIterator it(4, 3, 3);
        QVERIFY(it.hasNext());
        QVERIFY(it.getNext() == 5);
    }
};

QTEST_MAIN(BoardIteratorTest)
#include "BoardIteratorTest.moc"
