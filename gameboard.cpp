#include "gameboard.h"

GameBoard::GameBoard(QWidget *parentView)
    : QGraphicsScene(parentView)
{
    creature = new Creature(this);
    sceneRect = new QRectF(0,0,300,300);
    this->setSceneRect(*sceneRect);
}

void GameBoard::updateCreatures()
{
    creature->selfMove();
}

// QGraphicsScene* GameBoard::getQGraphicsScene()
// {
//     return QGraphicsScene;
// };
