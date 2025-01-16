#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QLayout>
#include <QGraphicsScene>
#include "gameboard.h"
#include <bitset>

namespace Ui {
class GamePage;
}

class GamePage : public QWidget
{
    Q_OBJECT

public:
    explicit GamePage(QWidget *parent = nullptr);
    ~GamePage();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    //GamePause *gamePause;
    GameBoard *gameBoard;
    //Creature *pecker;
    QRect *sceneRect;
    std::bitset<16> pressed = false;

private slots:
    void on_pushButton_gpPause_clicked();

private:
    Ui::GamePage *ui;
public slots:
    void send_movement();
signals:
    void s_pause_game();
    //void s_player_move_x(int);
    //void s_player_move_y(int);
    void s_player_movement(std::bitset<16>);
    void emit_b();
};

#endif // GAMEPAGE_H
