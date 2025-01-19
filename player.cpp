#include "player.h"

Player::Player(QGraphicsScene * scene, QString impath)
    : Creature{scene}
{
    image = new QImage(impath);
    pixItem = new QGraphicsPixmapItem(this);
    pixItem->setPixmap(QPixmap::fromImage(*image));
    //setTransformOriginPoint( image->size().width()/2, image->size().height()/2 );
    setTransformOriginPoint( pixItem->boundingRect().width()/2, pixItem->boundingRect().height()/2 );

    graphicsItemGroup->addToGroup(pixItem);

    this->setScale(30.0/pixItem->boundingRect().width());
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

