#include "playerfightmanager.h"
#include "gameboard.h"

PlayerFightManager::PlayerFightManager() {}

void PlayerFightManager::handle()
{
    for(auto& me: mmovables.getElements())
    {
        if(player->collidesWithItem(me,Qt::ItemSelectionMode::IntersectsItemBoundingRect))
        {
            qDebug() << "bot collison";
            me->deleteLater();
            pGB->removeCreature(me);
        }
    }
}

// void PlayerFightManager::erase(MapEntity* el)
// {
//     // auto cit = std::find_if(movables.begin(),movables.end(), [el](auto& r){ return el == r; } );
//     // if(cit != movables.end())
//     // {
//     //     movables.erase(cit);
//     // }
// }

// void PlayerFightManager::addMovable(Creature* c)
// {
//     // movables.insert(c);
//     // c->insertManager(this);

//     mmovables.add(c);
// }

void PlayerFightManager::setPlayer(Player* p)
{
    player = p;
    p->insertManager(&mmovables);
}

// PlayerFightManager::~PlayerFightManager()
// {
//     // for(auto& c : movables)
//     // {
//     //     c->eraseManager(this);
//     // }
//     // player->eraseManager(this);
// }
