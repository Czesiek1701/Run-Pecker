#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QGraphicsView>
#include "gamepause.h"
#include <QKeyEvent>
#include <QLayout>
#include <QGraphicsScene>
#include "creature.h"
#include "gameboard.h"

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

private slots:
    void on_pushButton_gpPause_clicked();

private:
    Ui::GamePage *ui;

signals:
    void s_pause_game();
    void s_player_move_x(int);
    void s_player_move_y(int);
};

#endif // GAMEPAGE_H
