#include "mapentity.h"
#include "entityregistry.h"

MapEntity::MapEntity(QGraphicsScene * scene)
    :QGraphicsObject()
{
    qDebug() << "Creating MapObject";
    scene->addItem(this);
    graphicsItemGroup = new QGraphicsItemGroup(this);
}

MapEntity::~MapEntity()
{
    for(auto* m : managers)
    {
        qDebug()<<"deleting manager";
        m->remove(this);
        qDebug()<<"manager deleted";
    }
}


void MapEntity::insertManager(EntityContainer* m)
{
    managers.insert(m);
}

void MapEntity::eraseManager(EntityContainer* m)
{
    managers.erase(m);
}
