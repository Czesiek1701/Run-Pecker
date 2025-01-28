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

    fixedObjects.push_back( new NonPenetratingWall(this) );
    // fixedObjects[0]->moveBy(-100,0);
    //qpp.moveTo(200,0);
    //qpp.lineTo(200,200);
    //qDebug()<<qpp;

    sceneViewRect = QRectF(0,0,850*2,400*2);
    background->renderBoundingRect = QRectF(0,0,
        (int)(sceneViewRect.width()*1.1),
        (int)(sceneViewRect.height()*1.1)
    );
    actualizeSceneRect();

}

void GameBoard::doStep()
{

    //mapControl->update(this->sceneRect());
    //qDebug()<<player->collidingItems(Qt::ItemSelectionMode::ContainsItemBoundingRect)[0];
    //qDebug()<<player->objectName();


    // if(player->collidesWithItem(fixedObjects[0],Qt::ItemSelectionMode::IntersectsItemBoundingRect))
    // {
    //     qDebug() << "wall collison";
    //     player->creatureWish={0,0};
    // }

    if( fixedObjects[0]->collidesWithItem( player ) )
    {
        qDebug() << "wall collison path";
        for (int i=0; i<fixedObjects[0]->shape().elementCount()-1; i++ )
        {
            //qDebug() << fixedObjects[0]->shape().elementAt(i);
            //qDebug() << QPointF(fixedObjects[0]->shape().elementAt(i));
            QPainterPath qpp(fixedObjects[0]->shape().elementAt(i));
            qpp.lineTo(fixedObjects[0]->shape().elementAt(i+1));
            qpp.closeSubpath();
            //qDebug()<<qpp;
            if ( player -> collidesWithPath( player->mapFromItem(fixedObjects[0],qpp)) )
            {
                qDebug()<< "Player colides with: \n" << qpp;
                //wyznaczyć normalną itd...
            }
        }
    }

    if(player->collidesWithItem(creatures[1],Qt::ItemSelectionMode::IntersectsItemBoundingRect))
    {
        qDebug()<<player->boundingRect();
        qDebug()<<player->shape();
        qDebug()<<creatures[1]->boundingRect();
        qDebug()<<creatures[1]->shape();
        qDebug()<<fixedObjects[0]->boundingRect();
        qDebug()<<fixedObjects[0]->shape();


        qDebug() << "bot collison";
        delete creatures[1];
        creatures.erase(creatures.begin()+1);
    }

    for(Creature* c:creatures)
    {
        c->actualize();
    }

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

