#include "playerfightmanager.h"
#include "gameboard.h"

PlayerFightManager::PlayerFightManager() {}

void PlayerFightManager::handle()
{
    if(mmovables.getElements().size()>1)
    {
        if(player->collidesWithItem(*mmovables.getElements().begin(),Qt::ItemSelectionMode::IntersectsItemBoundingRect))
        {
            qDebug() << "bot collison";
            //(*mmovables.getElements().begin())->deleteLater();       // !!!!!!!
            //pGB->removeCreature(*mmovables.getElements().begin());   // VISITOR
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
