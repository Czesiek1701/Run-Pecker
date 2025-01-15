#include "creature.h"
// #include "game.h"

Creature::Creature(QGraphicsScene * scene)
    :QGraphicsPixmapItem() , QObject(scene)
{
    qDebug() << "Creating creature...";
    //game_graphicsScene = scene;
    image = new QImage(":/data/pecker.bmp");
    this->setPixmap(QPixmap::fromImage(*image));
    //setTransformOriginPoint( image->size().width()/2, image->size().height()/2 );
    setTransformOriginPoint( boundingRect().width()/2, boundingRect().height()/2 );
    this->setScale(50.0/boundingRect().width());
    //pixItem = new QGraphicsPixmapItem(QPixmap::fromImage(*image));
    scene -> addItem(this);
    //boundingRect().width();
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

void Creature::getMovementWish(std::bitset<16> pressed)
{
    if(!(pressed[0] | pressed[2]))
    {
        creatureWish[1] = 0;
    }
    else if(pressed[0] & pressed[2])
    {
        creatureWish[1] = 0;
    }
    else if(pressed[0])
    {
        creatureWish[1] = -1;
    }
    else if(pressed[2])
    {
        creatureWish[1] = 1;
    }

    if(!(pressed[1] | pressed[3]))
    {
        creatureWish[0] = 0;
    }
    else if(pressed[1] & pressed[3])
    {
        creatureWish[0] = 0;
    }
    else if(pressed[1])
    {
        creatureWish[0] = -1;
    }
    else if(pressed[3])
    {
        creatureWish[0] = 1;
        rotateAroundCenter(20);
    }
}

// void Creature::setWishx(int d)
// {
//     creatureWish[0] = d;
// }
// void Creature::setWishy(int d)
// {
//     creatureWish[1] = d;
// }

void Creature::selfMove()
{
    this->moveBy( creatureWish[0]*step, creatureWish[1]*step );
}

void Creature::rotateAroundCenter(int angles)
{
    QGraphicsPixmapItem::setRotation( rotation()+20 );
}
