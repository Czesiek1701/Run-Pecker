#include "creature.h"
// #include "game.h"

Creature::Creature(QGraphicsScene * scene)
    :MapEntity(scene)
{
    qDebug() << "Creating creature";
}
Creature::~Creature()
{
    qDebug() << "Deleting creature.";
}

QRectF Creature::boundingRect() const
{
    return graphicsItemGroup->boundingRect();
}

void Creature::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);
}

void Creature::actualize()
{
    this->selfMove();
}

void Creature::selfMove()
{
    double mag = std::sqrt(creatureWish.rx()*creatureWish.rx()+creatureWish.ry()*creatureWish.ry());
    if ( std::abs(mag)>0.0625  )
    {
        this->moveBy( (creatureWish.rx()*step/mag), (creatureWish.ry()*step/mag) );
    }

}

void Creature::updateAngle()
{
    QGraphicsItem::setRotation(180/3.14159265*std::atan2(creatureWish.ry(), creatureWish.rx())+90);
}

QPointF Creature::center()
{
    return this->mapToScene( this->transformOriginPoint() );
}

void Creature::handleContact(const QGraphicsItem& fixObj)
{
    static QTransform st_qtr;

    for (int i=0; i<fixObj.shape().elementCount()-1; i++ )
    {
        static QPainterPath st_qpp;
        st_qpp.clear();
        st_qpp.moveTo(fixObj.shape().elementAt(i));
        st_qpp.lineTo(fixObj.shape().elementAt(i+1));

        // find collision sides of fixObj
        if ( this->collidesWithPath( this->mapFromItem(&fixObj ,st_qpp)) )
        {
            // in fixObj coords
            QPointF p_1 = QPointF(st_qpp.elementAt(0));
            QPointF p_c = fixObj.mapFromItem(&(*this), this->boundingRect().center());
            QPointF p_2 = QPointF(st_qpp.elementAt(1));

            // TO LINE COORDS
            p_c-=p_1;
            p_2-=p_1;
            qreal alpha = QLineF({0,0},p_2).angle()*3.14159/180;
            st_qtr.reset();
            st_qtr.rotateRadians(alpha);
            QPointF vlin = st_qtr.map(p_c)+QPointF(0,this->contact_radius);

            //QPointF p2lin = st_qtr.map(p_2); // p_2.y() not affect

            // to prevent corner jumps
            if(vlin.x()<this->step || (vlin.x() > (st_qtr.map(p_2).x()-this->step)))
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
                this->moveBy(vg.x(),vg.y());
            }

        }
    }
}
