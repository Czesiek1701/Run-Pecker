#include <QObject>
#include <QtTest/QtTest>
#include <QDebug>

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QWidget>
#include <QStackedWidget>

#include "gameboard.h"
#include "mainwindow.h"

class tst_GameBoard : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase()
    {
        qDebug() << "testing sth";
    }
    void checkCollision()
    {
        //GameBoard gameBoard(nullptr);



        QVERIFY(true); // check that a condition is satisfied
        QCOMPARE(1, 1); // compare two values
    }


    void testOpenCloseApp()
    {

        int argc = 1;
        char *argv[] = { "" };
        QApplication app(argc, argv);

        MainWindow mainWindow(nullptr);
        mainWindow.show();

        QTest::qWait(100);

        // Sprawdzamy, czy główne okno jest widoczne
        QVERIFY(mainWindow.isVisible());

        // Sprawdzamy, czy przycisk "Start" istnieje
        QStackedWidget *stackedWidget = mainWindow.findChild<QStackedWidget*>("stackedWidget");
        QVERIFY(stackedWidget != nullptr);

        // Sprawdzamy, czy przycisk "Start" istnieje
        QPushButton *startButton = mainWindow.findChild<QPushButton *>("pushButton_NewGmae");
        QVERIFY(startButton != nullptr);

        // Klikamy przycisk "Start" - symulujemy uruchomienie gry
        QTest::mouseClick(startButton, Qt::LeftButton);

        auto *gmptr = mainWindow.findChild<Game *>("game");
        QVERIFY(gmptr != nullptr);

        QTest::keyClick(&mainWindow, Qt::Key_P);
        GamePause* gps = mainWindow.findChild<GamePause*>("GamePause");
        QVERIFY(gps != nullptr);

        QPushButton *exitButton = mainWindow.findChild<QPushButton *>("pushButton_Exit");
        QVERIFY(exitButton != nullptr);

        QTest::mouseClick(exitButton, Qt::LeftButton);

        QPushButton *closeButton = mainWindow.findChild<QPushButton *>("pushButton_Close");
        QVERIFY(closeButton != nullptr);
        QTest::mouseClick(closeButton, Qt::LeftButton);

        QTest::qWait(200);
        QCoreApplication::quit();
        QTest::qWait(1000);
    }

    void cleanupTestCase()
    {
        qDebug() << "cleaning sth";
    }
};


QTEST_MAIN(tst_GameBoard);
#include "tst_GameBoard.moc"
