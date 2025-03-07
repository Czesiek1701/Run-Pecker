#ifndef ENTITYREGISTRY_H
#define ENTITYREGISTRY_H

#include <unordered_set>
#include <algorithm>
#include <QDebug>

//#include "mapentity.h"
//class IBehaviourManager;

class MapEntity;

class EntityContainer
{
private:
    std::unordered_set<MapEntity*> elements;
    //IBehaviourManager* owner;
public:
    EntityContainer()=default;
    ~EntityContainer();

    void add(MapEntity* sn);

    void remove(MapEntity* sn);

    const std::unordered_set<MapEntity*>& getElements();

};


#endif // ENTITYREGISTRY_H
