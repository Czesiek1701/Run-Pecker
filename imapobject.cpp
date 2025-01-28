#include "imapobject.h"

IMapObject::IMapObject(QGraphicsScene * scene)
    :QGraphicsObject()
{
    qDebug() << "Creating MapObject";
    scene->addItem(this);
    graphicsItemGroup = new QGraphicsItemGroup(this);
}

IMapObject::~IMapObject() {}
