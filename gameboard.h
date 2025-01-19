#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsView>
#include "creature.h"
#include <QGraphicsScene>
#include "player.h"
#include "bot.h"
#include <vector>
#include "mapcontrol.h"

class GameBoard : public QGraphicsScene
{
    Q_OBJECT
public:
    GameBoard(QWidget* parentView);
    virtual ~GameBoard() {}

    MapControl *mapControl;
    QRectF *sceneRect;
    Player *player;
    std::vector<Creature*> creatures;
    //Creature& player = *creature;
    // QGraphicsScene* getQGraphicsScene();
    void centerViewOnPlayer();
public slots:
    void updateCreatures();
};

#endif // GAMEBOARD_H
