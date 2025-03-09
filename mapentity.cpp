#include "mapentity.h"
#include "entityregistry.h"

MapEntity::MapEntity(QGraphicsScene * scene)
    :QGraphicsObject()
{
    //qDebug() << "Creating MapObject";
    scene->addItem(this);
    graphicsItemGroup = new QGraphicsItemGroup(this);
}

MapEntity::~MapEntity()
{
    for(auto* m : managers)
    {
        //qDebug()<<"deleting manager";
        m->remove(this);
        //qDebug()<<"manager deleted";
    }
}


void MapEntity::insertManager(EntityRegistry* m)
{
    managers.insert(m);
}

void MapEntity::eraseManager(EntityRegistry* m)
{
    managers.erase(m);
}
