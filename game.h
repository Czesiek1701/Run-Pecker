#ifndef GAME_H
#define GAME_H
#include <QSharedData>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include "gamepage.h"
#include "gamepause.h"
#include "creature.h"
#include <QTimer>

inline int TIMESTAMP = 15;

class Game : public QObject
{
    Q_OBJECT
public:
    Game(QWidget * gamePageParent);
    ~Game();
    bool running;
    QWidget *centralWidget;
    GamePage *gamePage;
    GamePause *gamePause;
    QGraphicsScene *gameScene;
    //Creature *pecker;
    QTimer *gameTimer;
    void start();
    void pause();
    //void close();
private:
    void makeConnections();
signals:
    void game_start();
    void game_pause();
    void s_update_central_vidget();

};

#endif // GAME_H
