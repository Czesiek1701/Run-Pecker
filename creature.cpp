#include "creature.h"
// #include "game.h"

Creature::Creature(QGraphicsScene * scene, QString impath=":/data/pecker.bmp")
    :QGraphicsPixmapItem() , QObject(scene)
{
    qDebug() << "Creating creature...";
    //game_graphicsScene = scene;
    image = new QImage(impath);
    this->setPixmap(QPixmap::fromImage(*image));
    //setTransformOriginPoint( image->size().width()/2, image->size().height()/2 );
    setTransformOriginPoint( boundingRect().width()/2, boundingRect().height()/2 );
    this->setScale(30.0/boundingRect().width());
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
        this->moveBy( creatureWish[0]*step/mag, creatureWish[1]*step/mag );
    }

}

void Creature::updateAngle()
{
    QGraphicsPixmapItem::setRotation(180/3.14159265*std::atan2(creatureWish[1], creatureWish[0])+90);
}
