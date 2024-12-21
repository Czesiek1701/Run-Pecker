#ifndef GAME_H
#define GAME_H
#include <QSharedData>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include "gameview.h"
#include "creature.h"

class Game : public QObject
{
    Q_OBJECT
public:
    Game(QWidget * parent);
    ~Game();
    bool running;
    GameView *gameView;
    Creature *pecker;
    void start();
    void pause();
signals:
    void game_start();
    void game_pause();

};

#endif // GAME_H
