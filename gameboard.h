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
    QRectF sceneRectt;
    QPointF sceneRectSizeHalf{800/2,450/2};
    Player *player;
    std::vector<Creature*> creatures;
    //Creature& player = *creature;
    // QGraphicsScene* getQGraphicsScene();
    void actualizeSceneRect();
public slots:
    void updateCreatures();
};

#endif // GAMEBOARD_H
