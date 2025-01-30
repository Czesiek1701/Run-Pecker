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
        //qDebug() << "wall collison path";
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
                // QPointF tl = player->boundingRectF.topLeft();
                // qDebug() << tl;
                // QLineF l = {QPointF(qpp.elementAt(0)),QPointF(qpp.elementAt(1))};
                // qreal an = -l.angle();

                QPointF p_1 = QPointF(qpp.elementAt(0));
                QPointF p_c = fixedObjects[0]->mapFromItem(player, player->boundingRectF.topLeft());
                p_c-=p_1;
                QPointF p_2 = QPointF(qpp.elementAt(1));
                p_2-=p_1;
                //QLineF p1p2 = {QPointF(qpp.elementAt(0)), QPointF(qpp.elementAt(1))};

                qreal alpha = QLineF({0,0},p_2).angle();
                //qreal beta = -1*p1pc.angle();
                qDebug() << alpha;
                qDebug() << p_2.x()*std::cos(alpha*3.14159/180)-p_2.y()*std::sin(alpha*3.14159/180);
                qDebug() << +1*p_2.x()*std::sin(alpha*3.14159/180)+p_2.y()*std::cos(alpha*3.14159/180);
                //qreal len_p1px =
                //qDebug() << p_c.x()*std::cos(alpha*3.14159/180)+p_c.y()*std::sin(alpha*3.14159/180);

                // TO LINE COORDS
                QPointF vlin = {(p_c.x()*std::cos(alpha*3.14159/180)-1*p_c.y()*std::sin(alpha*3.14159/180))*0, // temp
                                (+1*p_c.x()*std::sin(alpha*3.14159/180)+p_c.y()*std::cos(alpha*3.14159/180))}; // -
                qDebug() << vlin;
                QPointF vloc = {
                    vlin.x()*std::cos(alpha*3.14159/180)+(vlin.y())*std::sin(alpha*3.14159/180),
                    (-1)*vlin.x()*std::sin(alpha*3.14159/180)+(vlin.y())*std::cos(alpha*3.14159/180)
                };

                //vloc+=p_1;
                qDebug() << vloc;
                QPointF vg = -1*fixedObjects[0]->mapToScene(vloc);
                qDebug() << vg;

                // qDebug() << fixedObjects[0]->mapToItem(player, v);
                // QPointF vg = fixedObjects[0]->mapToScene(v); //-player->mapToScene(player->boundingRect().topLeft());
                //qDebug()<< player->boundingRect().topLeft();
                if(vlin.y()>0)
                {
                    //player->setPos(vg.x(),vg.y());
                    player->moveBy(vg.x(),vg.y());
                    qDebug() << player->mapToScene(player->boundingRect().center());
                    qDebug() << player->mapToScene(player->boundingRect().topLeft());
                }

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

