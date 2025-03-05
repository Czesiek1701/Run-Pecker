#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <vector>
#include "creature.h"
#include "mapentity.h"
#include "nonpenetratingwall.h"
#include "ibehaviourmanager.h"
#include <unordered_set>

class ContactManager : public IBehaviourManager
{
private:
    std::unordered_set<Creature*> movables;
    std::unordered_set<MapEntity*> stables;

public:
    ContactManager();
    virtual ~ContactManager() = default;

    //std::vector<Creature*> movables;
    //std::vector<NonPenetratingWall*> stables;

    void addMovable(Creature*);
    void addStable(MapEntity*);

    void handleContact(Creature& movCrt, const QGraphicsItem& fixObj);
    void handle();

    //void erase(Creature*);
    void erase(MapEntity*);

};

#endif // CONTACTMANAGER_H
