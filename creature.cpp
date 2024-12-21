#include "creature.h"

Creature::Creature(QGraphicsScene * scene) {
    qDebug() << "Creating creature...";
    //game_graphicsScene = scene;
    image = new QImage(":/data/pecker.bmp");
    pixItem = new QGraphicsPixmapItem(QPixmap::fromImage(*image));
    scene -> addItem(pixItem);
    qDebug() << "Created creature.";
}
Creature::~Creature()
{
    qDebug() << "Deleting creature...";
    delete pixItem;
    delete image;
    qDebug() << "Deleted creature.";
}
void Creature::creatureMove(int x, int y)
{
    pixItem->moveBy(x,y);
}
QGraphicsPixmapItem *Creature::getPixItem()
{
    return pixItem;
}
