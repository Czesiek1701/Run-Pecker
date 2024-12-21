#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
#include <QGraphicsScene>
#include <QKeyEvent>

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

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_Settings_clicked();

    void on_pushButton_Close_clicked();

    void on_pushButton_Play_clicked();

    void on_pushButton_refresh_clicked();

private:
    Ui::MainWindow *ui;
    enum ePages
    {
        p_start,
        p_settings,
        p_game
    };
    Game * game;
    QWidget * gamePage;

public:
    //virtual bool eventFilter(QObject *object, QEvent *event)override;
signals:
    void click_R();
};
#endif // MAINWINDOW_H
