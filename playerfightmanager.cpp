#include "playerfightmanager.h"
#include "gameboard.h"

PlayerFightManager::PlayerFightManager() {}

void PlayerFightManager::handle()
{
    if(movables.size()>1)
    {
        if(player->collidesWithItem(*movables.begin(),Qt::ItemSelectionMode::IntersectsItemBoundingRect))
        {
            qDebug() << "bot collison";
            (*movables.begin())->deleteLater();
            pGB->removeCreature(*movables.begin());
        }
    }
}

void PlayerFightManager::erase(MapEntity* el)
{
    auto cit = std::find_if(movables.begin(),movables.end(), [el](auto& r){ return el == r; } );
    if(cit != movables.end())
    {
        movables.erase(cit);
    }
}

void PlayerFightManager::addMovable(Creature* c)
{
    movables.insert(c);
    c->insertManager(this);
}

void PlayerFightManager::setPlayer(Player* p)
{
    player = p;
    p->insertManager(this);
}

PlayerFightManager::~PlayerFightManager()
{
    for(auto& c : movables)
    {
        c->eraseManager(this);
    }
    player->eraseManager(this);
}
