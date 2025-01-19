#include "creature.h"
// #include "game.h"

Creature::Creature(QGraphicsScene * scene)
    :QGraphicsObject()
{
    qDebug() << "Creating creature...";
    scene->addItem(this);
    graphicsItemGroup = new QGraphicsItemGroup(this);
    //game_graphicsScene = scene;
    //pixItem = new QGraphicsPixmapItem(QPixmap::fromImage(*image));
    //boundingRect().width();
    qDebug() << "Created creature.";
}
Creature::~Creature()
{
    qDebug() << "Deleting creature...";
    //delete pixItem;
    //delete image;
    qDebug() << "Deleted creature.";
}

QRectF Creature::boundingRect() const
{
    //return pixItem -> boundingRect();
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
// QGraphicsPixmapItem *Creature::getPixItem()
// {
//     return pixItem;x
// }


// void Creature::setWishx(int d)
// {
//     creatureWish[0] = d;
// }
// void Creature::setWishy(int d)
// {
//     creatureWish[1] = d;
// }

void Creature::actualize()
{
    this->selfMove();
}

void Creature::selfMove()
{
    double mag = std::sqrt(creatureWish[0]*creatureWish[0]+creatureWish[1]*creatureWish[1]);
    if ( std::abs(mag)>0.0625  )
    {
        //qDebug()<<mag;
        this->moveBy( int(creatureWish[0]*step/mag), int(creatureWish[1]*step/mag) );
    }

}

void Creature::updateAngle()
{
    QGraphicsItem::setRotation(180/3.14159265*std::atan2(creatureWish[1], creatureWish[0])+90);
}
