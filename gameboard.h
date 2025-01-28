#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsView>
#include "creature.h"
#include <QGraphicsScene>
#include "player.h"
#include "bot.h"
#include <vector>
#include "background.h"
#include "nonpenetratingwall.h"

class GameBoard : public QGraphicsScene
{
    Q_OBJECT
public:
    GameBoard(QWidget* parentView);
    ~GameBoard() {}

    //QPointF sceneRectSize{800,450};
    QRectF sceneViewRect;
    QRectF sceneRenderRect;

    Background *background;
    Player *player;
    std::vector<Creature*> creatures;
    std::vector<NonPenetratingWall*> fixedObjects;
    //Creature& player = *creature;
    // QGraphicsScene* getQGraphicsScene();
    //QPainterPath qpp;
    void actualizeSceneRect();
public slots:
    void doStep();
};

#endif // GAMEBOARD_H
