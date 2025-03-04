#include "gameboard.h"
#include <QBrush>

GameBoard::GameBoard(QWidget *parentView)
    : QGraphicsScene(parentView),
    contactManager(creatures, fixedObjects)
{
    qDebug()<<"Creating game board";



    background = new Background(this);
    background->setZValue(-100);

    player = new Player(this);
    player->setZValue(1);
    creatures.push_back(player);

    for (int i=0;i<5;i++)
    {
        creatures.push_back(new Bot(this));
        creatures[i+1]->setZValue(0);
    }


    qDebug()<<12;

    fixedObjects.push_back( new NonPenetratingWall(this, QRectF(0,0,100,1000)) );
    (*(fixedObjects.end()-1))->setPos(-200,-200);
    fixedObjects.push_back( new NonPenetratingWall(this, QRectF(0,0,1000,100)) );
    (*(fixedObjects.end()-1))->setPos(-200,-200);
    fixedObjects.push_back( new NonPenetratingWall(this, QRectF(0,0,100,1200)) );
    (*(fixedObjects.end()-1))->setPos(800,-200);
    fixedObjects.push_back( new NonPenetratingWall(this, QRectF(0,0,1200,100)) );
    (*(fixedObjects.end()-1))->setPos(-200,800);
    // fixedObjects[0]->moveBy(-100,0);
    //qpp.moveTo(200,0);
    //qpp.lineTo(200,200);
    //qDebug()<<qpp;

    contactManager.movables = creatures;
    contactManager.stables = fixedObjects;

    sceneViewRect = QRectF(0,0,850*2,400*2);
    background->renderBoundingRect = QRectF(0,0,
        (int)(sceneViewRect.width()*1.1),
        (int)(sceneViewRect.height()*1.1)
    );
    actualizeSceneRect();

}

void GameBoard::doStep()
{
    // for(Creature* c: creatures)
    // {
    //     for(QGraphicsItem* w: fixedObjects)
    //     {
    //         if( w->collidesWithItem( c ) )
    //         {
    //             handleContact(*c, *w);
    //         }
    //     }
    // }
    contactManager.handleContacts();

    if(creatures.size()>1)
    {
        if(player->collidesWithItem(creatures[1],Qt::ItemSelectionMode::IntersectsItemBoundingRect))
        {
            qDebug() << "bot collison";
            creatures[1]->deleteLater();
            creatures.erase(creatures.begin()+1);

        }
    }

    for(Creature* c:creatures)
    {
        c->actualize();
    }

    actualizeSceneRect();
}

// void GameBoard::handleContact(Creature& movCrt, const QGraphicsItem& fixObj)
// {
//     static QTransform st_qtr;

//     for (int i=0; i<fixObj.shape().elementCount()-1; i++ )
//     {
//         static QPainterPath st_qpp;
//         st_qpp.clear();
//         st_qpp.moveTo(fixObj.shape().elementAt(i));
//         st_qpp.lineTo(fixObj.shape().elementAt(i+1));

//         // find collision sides of fixObj
//         if ( movCrt.collidesWithPath( movCrt.mapFromItem(&fixObj ,st_qpp)) )
//         {
//             // in fixObj coords
//             QPointF p_1 = QPointF(st_qpp.elementAt(0));
//             QPointF p_c = fixObj.mapFromItem(&movCrt, movCrt.boundingRect().center());
//             QPointF p_2 = QPointF(st_qpp.elementAt(1));

//             // TO LINE COORDS
//             p_c-=p_1;
//             p_2-=p_1;
//             qreal alpha = QLineF({0,0},p_2).angle()*3.14159/180;
//             st_qtr.reset();
//             st_qtr.rotateRadians(alpha);
//             QPointF vlin = st_qtr.map(p_c)+QPointF(0,movCrt.contact_radius);

//             //QPointF p2lin = st_qtr.map(p_2); // p_2.y() not affect

//             // to prevent corner jumps
//             if(vlin.x()<movCrt.step || (vlin.x() > (st_qtr.map(p_2).x()-movCrt.step)))
//             {
//                 continue;
//             }

//             // TO WALL ITEM COORDS
//             st_qtr.reset();
//             st_qtr.rotateRadians(-alpha);
//             QPointF vloc = st_qtr.map(QPointF(0,vlin.y()));

//             // TO SCENE COORDS
//             st_qtr.reset();
//             st_qtr.rotate(fixObj.rotation());
//             QPointF vg = st_qtr.map(-vloc);

//             // CHECK DEPTH
//             if(vlin.y()>(0))
//             {
//                 movCrt.moveBy(vg.x(),vg.y());
//             }

//         }
//     }
// }

void GameBoard::actualizeSceneRect()
{
    //QPointF c=player->mapToScene( player->transformOriginPoint() );
    //QPointF c=player->center();

    sceneViewRect.moveCenter(player->center());
    this->setSceneRect(sceneViewRect);

    background->renderBoundingRect.moveCenter(player->center());
}

