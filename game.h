#ifndef GAME_H
#define GAME_H
#include <QSharedData>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include "gamepage.h"
#include "gamepause.h"
#include "creature.h"
#include <QTimer>
#include <QLayout>
#include <qstackedlayout.h>

inline int TIMESTAMP = 1000/120; // 1000[ms]/x[Hz]

class Game : public QWidget
{
    Q_OBJECT
public:
    Game(QWidget * gamePageParent);
    ~Game();
    //QWidget * gamePageParent;
    bool running;
    //QWidget *centralWidget;

    // QLayout *qLayoutG;
    // QLayout *qLayoutS;
    QStackedLayout *stackedLayout;


    GamePage *gamePage;
    GamePause *gamePause;
    QGraphicsScene *gameScene;
    //Creature *pecker;
    QTimer *gameTimer;
    void start();
    void pause();
    //void close();
private:
    void makeGamePageConnections();
    void makeGamePauseConnections();
signals:
    void game_start();
    void game_pause();
    void game_close();
    void s_update_central_vidget();
    void s_new_game_pause();

};

#endif // GAME_H
