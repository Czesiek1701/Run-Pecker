#include <QObject>
#include <QtTest/QtTest>
#include <QTest>
#include <QDebug>

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QWidget>
#include <QStackedWidget>

#include "gameboard.h"
#include "mainwindow.h"

#include "game.h"

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
        QTest::qWait(10);

        auto *gmptr = mainWindow.findChild<Game *>("game");
        QVERIFY(gmptr != nullptr);

        QTest::keyClick(&mainWindow, Qt::Key_P);
        QTest::qWait(10);
        GamePause* gps = mainWindow.findChild<GamePause*>("GamePause");
        QVERIFY(gps != nullptr);

        QPushButton *exitButton = mainWindow.findChild<QPushButton *>("pushButton_Exit");
        QVERIFY(exitButton != nullptr);

        QTest::mouseClick(exitButton, Qt::LeftButton);
        QTest::qWait(10);

        QPushButton *closeButton = mainWindow.findChild<QPushButton *>("pushButton_Close");
        QVERIFY(closeButton != nullptr);
        QTest::mouseClick(closeButton, Qt::LeftButton);
        QTest::qWait(10);

        QVERIFY(!mainWindow.isVisible());

    }

    void testDoStepPerformance()
    {
        Game* game = new Game(nullptr);

        game->gameTimer->stop();

        QElapsedTimer timer;
        timer.start();  // Rozpoczęcie pomiaru czasu

        const int STEPNUM = 1000;
        for (int i=0; i<STEPNUM; i++)
        {
            game->gamePage->gameBoard->doStep();
        }

        // Sprawdzanie czasu
        qint64 elapsed = timer.elapsed();

        game->deleteLater();

        QTest::qWait(10);


        qDebug() << "TIME FOR 1 x doStep() WAS: " << elapsed*1.0/STEPNUM << " mili s";
        qDebug() << "TIME FOR 1 x 60Hz is:" << 1000*1.0/60 << " mili s";
        qDebug() << "safety coefficient: " << (STEPNUM*1000*1.0/60)/elapsed;
        QVERIFY(elapsed < STEPNUM*(1000*1.0/60) );  // Zakładając, że wykonanie powinno być poniżej 500ms


    }

    void cleanupTestCase()
    {
        if (QCoreApplication::instance() == nullptr) {
            qDebug() << "Aplikacja już nie działa!";
        }
        qDebug() << "cleaning sth";
    }
};


QTEST_MAIN(tst_GameBoard);
#include "tst_GameBoard.moc"
