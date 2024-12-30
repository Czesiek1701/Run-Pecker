#include "creature.h"
#include "game.h"

Creature::Creature(QGraphicsScene * scene)
    :QGraphicsPixmapItem() , QObject(scene)
{
    qDebug() << "Creating creature...";
    //game_graphicsScene = scene;
    image = new QImage(":/data/pecker.bmp");
    this->setPixmap(QPixmap::fromImage(*image));
    //pixItem = new QGraphicsPixmapItem(QPixmap::fromImage(*image));
    scene -> addItem(this);
    qDebug() << "Created creature.";
}
Creature::~Creature()
{
    qDebug() << "Deleting creature...";
    //delete pixItem;
    delete image;
    qDebug() << "Deleted creature.";
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
//     return pixItem;
// }

void Creature::setWishx(int d)
{
    creatureWish[0] = d;
}
void Creature::setWishy(int d)
{
    creatureWish[1] = d;
}

void Creature::selfMove()
{
    this->moveBy( creatureWish[0]*step, creatureWish[1]*step );
}
