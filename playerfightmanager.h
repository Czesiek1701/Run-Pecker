#ifndef PLAYERFIGHTMANAGER_H
#define PLAYERFIGHTMANAGER_H

#include "ibehaviourmanager.h"
#include "creature.h"
#include "player.h"
#include "entityregistry.h"

class GameBoard;

class PlayerFightManager : public IBehaviourManager
{
private:
    //std::unordered_set<Creature*> movables;
    Player* player;
public:

    EntityContainer mmovables;

    PlayerFightManager();
    //~PlayerFightManager();
    virtual void handle();
    //virtual void erase(MapEntity*);

    //void addMovable(Creature*);
    void setPlayer(Player*);

    GameBoard* pGB;
};

#endif // PLAYERFIGHTMANAGER_H
