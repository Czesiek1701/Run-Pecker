#include "mapentity.h"

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
        m->erase(this);
        qDebug()<<"manager deleted";
    }
}


void MapEntity::insertManager(IBehaviourManager* m)
{
    managers.insert(m);
}

void MapEntity::eraseManager(IBehaviourManager* m)
{
    managers.erase(m);
}
