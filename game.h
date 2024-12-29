#ifndef GAME_H
#define GAME_H
#include <QSharedData>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include "gamepage.h"
#include "creature.h"

class Game : public QObject
{
    Q_OBJECT
public:
    Game(QWidget * gamePageParent);
    ~Game();
    bool running;
    GamePage *gamePage;
    Creature *pecker;
    void start();
    void pause();
    //void close();
signals:
    void game_start();
    void game_pause();

};

#endif // GAME_H
