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

Bot::Bot(QGraphicsScene * scene, QString impath)
    : Creature{scene, impath}
{
    this->setRandomDest();
}

void Bot::setRandomDest()
{
    dest.rx() = QTime::currentTime().msec()%600;
    dest.ry() = (QTime::currentTime().msec()*201)%600;

    creatureWish[0] = dest.rx()-Creature::pos().rx();
    creatureWish[1] = dest.ry()-Creature::pos().ry();

    updateAngle();
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
