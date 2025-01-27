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
    ~GameBoard() {}

    //QPointF sceneRectSize{800,450};
    QRectF sceneViewRect;
    QRectF sceneRenderRect;

    MapControl *mapControl;
    Player *player;
    std::vector<Creature*> creatures;
    //Creature& player = *creature;
    // QGraphicsScene* getQGraphicsScene();
    void actualizeSceneRect();
public slots:
    void updateCreatures();
};

#endif // GAMEBOARD_H
