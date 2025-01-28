#include "gameboard.h"
#include <QBrush>

GameBoard::GameBoard(QWidget *parentView)
    : QGraphicsScene(parentView)
{
    qDebug()<<"Creating game board";

    background = new Background(this);
    background->setZValue(-100);

    player = new Player(this, ":/data/pecker.bmp");
    player->setZValue(1);
    creatures.push_back(player);

    for (int i=0;i<5;i++)
    {
        creatures.push_back(new Bot(this, ":/data/bot.bmp"));
        creatures[i+1]->setZValue(0);
    }
    qDebug()<<12;

    sceneViewRect = QRectF(0,0,850*2,400*2);
    background->renderBoundingRect = QRectF(0,0,
        (int)(sceneViewRect.width()*1.1),
        (int)(sceneViewRect.height()*1.1)
    );
    actualizeSceneRect();

}

void GameBoard::doStep()
{
    for(Creature* c:creatures)
    {
        c->actualize();
    }

    //mapControl->update(this->sceneRect());

    actualizeSceneRect();
}

void GameBoard::actualizeSceneRect()
{
    //QPointF c=player->mapToScene( player->transformOriginPoint() );
    //QPointF c=player->center();

    sceneViewRect.moveCenter(player->center());
    this->setSceneRect(sceneViewRect);

    background->renderBoundingRect.moveCenter(player->center());
}

