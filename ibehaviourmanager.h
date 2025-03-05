#ifndef IBEHAVIOURMANAGER_H
#define IBEHAVIOURMANAGER_H

//#include "mapentity.h"

class MapEntity;

class IBehaviourManager
{
private:
public:
    IBehaviourManager();
    virtual ~IBehaviourManager() = default;
    virtual void handle() = 0;
    virtual void erase(MapEntity*) = 0;
};

#endif // IBEHAVIOURMANAGER_H
