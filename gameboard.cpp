#include "gameboard.h"
#include <QBrush>

GameBoard::GameBoard(QWidget *parentView)
    : QGraphicsScene(parentView)
{
    qDebug()<<"Creating game board";

    mapControl = new MapControl(this);
    mapControl->setZValue(-100);

    player = new Player(this, ":/data/pecker.bmp");
    player->setZValue(1);
    creatures.push_back(player);

    for (int i=0;i<5;i++)
    {
        creatures.push_back(new Bot(this, ":/data/bot.bmp"));
        creatures[i+1]->setZValue(0);
    }
    qDebug()<<12;

    //sceneRectt = QRectF(-300,-10,300,10);
    this->setSceneRect(QRectF());

    actualizeSceneRect();

}


void GameBoard::updateCreatures()
{
    for(Creature* c:creatures)
    {
        c->actualize();
    }

    mapControl->update(-200,-200,400,400);

    actualizeSceneRect();
}

void GameBoard::actualizeSceneRect()
{
    QPointF c=player->mapToScene( player->transformOriginPoint() );
    this->setSceneRect(
        c.x()-sceneRectSizeHalf.x(),
        c.y()-sceneRectSizeHalf.y(),
        sceneRectSizeHalf.x()*2 ,
        sceneRectSizeHalf.y()*2
    );
}

