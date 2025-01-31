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

    fixedObjects.push_back( new NonPenetratingWall(this, QRectF(0,0,360,360)) );
    (*(fixedObjects.end()-1))->setPos(200,0);
    fixedObjects.push_back( new NonPenetratingWall(this, QRectF(0,0,200,100)) );
    (*(fixedObjects.end()-1))->setPos(300,400);
    fixedObjects.push_back( new NonPenetratingWall(this, QRectF(0,0,150,50)) );
    (*(fixedObjects.end()-1))->setPos(50,200);
    fixedObjects.push_back( new NonPenetratingWall(this, QRectF(0,0,300,50)) );
    (*(fixedObjects.end()-1))->setPos(-300,50);
    fixedObjects.push_back( new NonPenetratingWall(this, QRectF(0,0,50,300)) );
    (*(fixedObjects.end()-1))->setPos(-100,200);
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
    for(Creature* c: creatures)
    {
        for(QGraphicsItem* w: fixedObjects)
        {
            if( w->collidesWithItem( c ) )
            {
                handleContact(*c, *w);
            }
        }
    }

    if(player->collidesWithItem(creatures[1],Qt::ItemSelectionMode::IntersectsItemBoundingRect))
    {
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

void GameBoard::handleContactOld(Creature& movCrt, QGraphicsItem& fixObj)
{
    for (int i=0; i<fixObj.shape().elementCount()-1; i++ )
    {
        QPainterPath qpp;
        qpp.moveTo(fixObj.shape().elementAt(i));
        qpp.lineTo(fixObj.shape().elementAt(i+1));

        // find collision sides of fixObj
        if ( movCrt.collidesWithPath( movCrt.mapFromItem(&fixObj ,qpp)) )
        {
            // in fixObj coords
            QPointF p_1 = QPointF(qpp.elementAt(0));
            QPointF p_c = fixObj.mapFromItem(&movCrt, movCrt.boundingRect().center());
            QPointF p_2 = QPointF(qpp.elementAt(1));

            // TO LINE COORDS
            p_c-=p_1;
            p_2-=p_1;
            qreal alpha = QLineF({0,0},p_2).angle()*3.14159/180;
            qreal sin_alpha = std::sin(alpha);
            qreal cos_alpha = std::cos(alpha);
            QPointF vlin = {
                            (p_c.x()*cos_alpha-1*p_c.y()*sin_alpha),
                            (+1*p_c.x()*sin_alpha+p_c.y()*cos_alpha)+ movCrt.contact_radius
                        };
            // to prevent corner jumps
            if(vlin.x()<movCrt.step+1 || (vlin.x() > (p_2.x()*cos_alpha-1*p_2.y()*sin_alpha)-movCrt.step-1))
            {
                continue;
            }

            // TO WALL ITEM COORDS
            QPointF vloc = {
                (vlin.y())*sin_alpha,       //0*vlin.x()*cos_alpha+(vlin.y())*sin_alpha,
                (vlin.y())*cos_alpha        //0*(-1)*vlin.x()*sin_alpha+(vlin.y())*cos_alpha
            };

            // TO SCENE COORDS
            QPointF vg = -1*fixObj.mapToScene(vloc)+fixObj.pos();

            // CHECK DEPTH
            if(vlin.y()>(0))
            {
                movCrt.moveBy(vg.x(),vg.y());
                qDebug() << vlin;
                qDebug() << vloc;
                qDebug() << vg;
            }

        }
    }
}

void GameBoard::handleContact(Creature& movCrt, const QGraphicsItem& fixObj)
{
    static QTransform st_qtr;

    for (int i=0; i<fixObj.shape().elementCount()-1; i++ )
    {
        static QPainterPath st_qpp;
        st_qpp.clear();
        st_qpp.moveTo(fixObj.shape().elementAt(i));
        st_qpp.lineTo(fixObj.shape().elementAt(i+1));

        // find collision sides of fixObj
        if ( movCrt.collidesWithPath( movCrt.mapFromItem(&fixObj ,st_qpp)) )
        {
            // in fixObj coords
            QPointF p_1 = QPointF(st_qpp.elementAt(0));
            QPointF p_c = fixObj.mapFromItem(&movCrt, movCrt.boundingRect().center());
            QPointF p_2 = QPointF(st_qpp.elementAt(1));

            // TO LINE COORDS
            p_c-=p_1;
            p_2-=p_1;
            qreal alpha = QLineF({0,0},p_2).angle()*3.14159/180;
            st_qtr.reset();
            st_qtr.rotateRadians(alpha);
            QPointF vlin = st_qtr.map(p_c)+QPointF(0,movCrt.contact_radius);

            //QPointF p2lin = st_qtr.map(p_2); // p_2.y() not affect

            // to prevent corner jumps
            if(vlin.x()<movCrt.step*0+0 || (vlin.x() > (st_qtr.map(p_2).x()-movCrt.step*0-0)))
            {
                continue;
            }

            // TO WALL ITEM COORDS
            st_qtr.reset();
            st_qtr.rotateRadians(-alpha);
            QPointF vloc = st_qtr.map(QPointF(0,vlin.y()));

            // TO SCENE COORDS
            st_qtr.reset();
            st_qtr.rotate(fixObj.rotation());
            QPointF vg = st_qtr.map(-vloc);

            // CHECK DEPTH
            if(vlin.y()>(0))
            {
                movCrt.moveBy(vg.x(),vg.y());
            }

        }
    }
}

void GameBoard::actualizeSceneRect()
{
    //QPointF c=player->mapToScene( player->transformOriginPoint() );
    //QPointF c=player->center();

    sceneViewRect.moveCenter(player->center());
    this->setSceneRect(sceneViewRect);

    background->renderBoundingRect.moveCenter(player->center());
}

