#include "creature.h"
// #include "game.h"

Creature::Creature(QGraphicsScene * scene)
    :QGraphicsObject()
{
    qDebug() << "Creating creature...";
    scene->addItem(this);
    graphicsItemGroup = new QGraphicsItemGroup(this);
    qDebug() << "Created creature.";
}
Creature::~Creature()
{
    qDebug() << "Deleting creature...";
    //delete graphicsItemGroup;
    qDebug() << "Deleted creature.";
}

QRectF Creature::boundingRect() const
{
    return boundingRectF;
}

void Creature::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);
}

void Creature::creatureMove(int x=10, int y=10)
{
    this->moveBy(x,y);
}
void Creature::creatureDummyMove()
{
    creatureMove(10, 10);
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
