#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
// #include "OldgamePage.h"
#include <QGraphicsScene>
#include <QKeyEvent>
// #include "gamepage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event) override;

private slots:

    void on_pushButton_NewGmae_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_Settings_clicked();

    void on_pushButton_Close_clicked();

    void on_pushButton_5_clicked();

    void close_game();

    void on_pushButton_clicked();

    void on_pushButton_Back_clicked();

    void updateCentralWidget();

private:
    Ui::MainWindow *ui;
    enum ePages
    {
        p_start,
        p_settings,
        p_game
    };
    Game * game;
    //OldGamePage *OldgamePage;
    //GamePage *gamePage;


public:
    //virtual bool eventFilter(QObject *object, QEvent *event)override;
signals:
    void click_R();
};
#endif // MAINWINDOW_H
