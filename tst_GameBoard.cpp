#include <QObject>
#include <QtTest/QtTest>
#include <QDebug>

class tst_GameBoard : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase()
    {
        qDebug() << "testing sth";
    }
    void myFirstTest()
    {
        QVERIFY(true); // check that a condition is satisfied
        QCOMPARE(1, 1); // compare two values
    }
};


QTEST_MAIN(tst_GameBoard);
#include "tst_GameBoard.moc"
