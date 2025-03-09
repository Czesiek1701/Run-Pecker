#ifndef NONPENETRATIONMANAGER_H
#define NONPENETRATIONMANAGER_H

#include <vector>
#include "creature.h"
#include "mapentity.h"
#include "nonpenetratingwall.h"
#include "ibehaviourmanager.h"
#include <unordered_set>
#include "entityregistry.h"

class NonPenetrationManager : public IBehaviourManager
{
private:
    //std::unordered_set<Creature*> movables;
    //std::unordered_set<MapEntity*> stables;
public:
    NonPenetrationManager();
    //virtual ~NonPenetrationManager();

    EntityRegistry mmovables;
    EntityRegistry mstables;

    //std::vector<Creature*> movables;
    //std::vector<NonPenetratingWall*> stables;

    //void addMovable(Creature*);
    //void addStable(MapEntity*);

    //void handleContact(Creature& movCrt, const QGraphicsItem& fixObj);
    void handle();

    //void erase(Creature*);
    //void erase(MapEntity*);

};

#endif // NONPENETRATIONMANAGER_H
