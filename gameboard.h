#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsView>
#include "creature.h"
#include <QGraphicsScene>

class GameBoard : public QGraphicsScene
{
    Q_OBJECT
public:
    GameBoard(QWidget* parentView);
    virtual ~GameBoard() {}
    QRectF *sceneRect;
    Creature *creature;
    Creature& player = *creature;
    // QGraphicsScene* getQGraphicsScene();
public slots:
    void updateCreatures();
};

#endif // GAMEBOARD_H
