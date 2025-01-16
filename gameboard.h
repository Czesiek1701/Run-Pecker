#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsView>
#include "creature.h"
#include <QGraphicsScene>
#include "player.h"
#include "bot.h"

class GameBoard : public QGraphicsScene
{
    Q_OBJECT
public:
    GameBoard(QWidget* parentView);
    virtual ~GameBoard() {}
    QRectF *sceneRect;
    Player *player;
    Bot *bot[3];
    //Creature& player = *creature;
    // QGraphicsScene* getQGraphicsScene();
public slots:
    void updateCreatures();
};

#endif // GAMEBOARD_H
