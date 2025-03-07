#include "entityregistry.h"
#include "mapentity.h"

void EntityContainer::add(MapEntity* sn)
{
    elements.insert(sn);
    sn->insertManager(this);
}

void EntityContainer::remove(MapEntity* sn)
{
    auto cit = std::find_if(elements.begin(),elements.end(), [sn](auto& r){ return sn == r; } );
    if(cit != elements.end())
    {
        elements.erase(cit);
    }
}

const std::unordered_set<MapEntity*>& EntityContainer::getElements()
{
    return elements;
}

EntityContainer::~EntityContainer()
{
    for(auto& sn : elements)
    {
        qDebug() << "removing entity from container";
        sn->eraseManager(this);
        qDebug() << "entity removed";
    }
}
