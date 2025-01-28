#include "creature.h"
// #include "game.h"

Creature::Creature(QGraphicsScene * scene)
    :IMapObject(scene)
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
