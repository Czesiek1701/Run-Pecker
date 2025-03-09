#ifndef ENTITYREGISTRY_H
#define ENTITYREGISTRY_H

#include <unordered_set>
#include <algorithm>
#include <QDebug>

//#include "mapentity.h"
//class IBehaviourManager;

class MapEntity;

class EntityRegistry
{
private:
    std::unordered_set<MapEntity*> elements;
    //IBehaviourManager* owner;
public:
    EntityRegistry()=default;
    ~EntityRegistry();

    void add(MapEntity* sn);

    void remove(MapEntity* sn);

    const std::unordered_set<MapEntity*>& getElements();

};


#endif // ENTITYREGISTRY_H
