#include "player.h"

Player::Player(QGraphicsScene * scene, QString impath)
    : Creature{scene,impath}
{

}


void Player::getMovementWish(std::bitset<16> pressed)
{
    if(!(pressed[0] | pressed[2]))
    {
        creatureWish[1] = 0;
    }
    else if(pressed[0] & pressed[2])
    {
        creatureWish[1] = 0;
    }
    else if(pressed[0])
    {
        creatureWish[1] = -1;
        updateAngle();
    }
    else if(pressed[2])
    {
        creatureWish[1] = 1;
        updateAngle();
    }

    if(!(pressed[1] | pressed[3]))
    {
        creatureWish[0] = 0;
    }
    else if(pressed[1] & pressed[3])
    {
        creatureWish[0] = 0;
    }
    else if(pressed[1])
    {
        creatureWish[0] = -1;
        updateAngle();
    }
    else if(pressed[3])
    {
        creatureWish[0] = 1;
        updateAngle();
    }
}
