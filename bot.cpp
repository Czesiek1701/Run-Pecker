#include "bot.h"
#include <QTime>

// bool operator<=(QPoint p1, QPoint p2)
// {
//     return (p1.rx()<=p2.rx())&&(p1.ry()<=p2.ry());
// }
// bool operator>=(QPoint p1, QPoint p2)
// {
//     return (p1.rx()>=p2.rx())&&(p1.ry()>=p2.ry());
// }

int Bot::static_bot_rand;

Bot::Bot(QGraphicsScene * scene, QString impath)
    : Creature{scene, impath}
{
    this->setRandomDest();
}

void Bot::setRandomDest()
{
    dest.rx() = (QTime::currentTime().msec()*Bot::static_bot_rand)%600;
    dest.ry() = (QTime::currentTime().msec()*201*Bot::static_bot_rand)%600;

    creatureWish[0] = dest.rx()-Creature::pos().rx();
    creatureWish[1] = dest.ry()-Creature::pos().ry();

    updateAngle();
    Bot::static_bot_rand+=317;
}

void Bot::actualize()
{
    this->selfMove();
    // if(Creature::QGraphicsPixmapItem::contains(
    //         dest-Creature::QGraphicsPixmapItem::pos()
    //         +Creature::QGraphicsPixmapItem::boundingRect().topRight()
    //         -Creature::QGraphicsPixmapItem::boundingRect().bottomLeft()
    //         )
    //     )
    if ( abs(Creature::QGraphicsPixmapItem::pos().rx()-dest.rx())<50
        && abs(Creature::QGraphicsPixmapItem::pos().ry()-dest.ry())<50 )
    {
        setRandomDest();
    }
}
