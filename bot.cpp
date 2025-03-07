#include "bot.h"
#include <QTime>

int Bot::static_bot_rand;

Bot::Bot(QGraphicsScene * scene)
    :Bot(scene, ":/data/bot.bmp")
{
    this->setZValue(0);
}

Bot::Bot(QGraphicsScene * scene, QString impath)
    : Creature{scene}
{
    this->setObjectName("bot");

    image = QImage(impath);
    pixItem = new QGraphicsPixmapItem(this);
    pixItem->setPixmap(QPixmap::fromImage(image));

    setTransformOriginPoint( pixItem->boundingRect().width()/2, pixItem->boundingRect().height()/2 );
    pixItem->setScale(30.0/pixItem->boundingRect().width());
    this->contact_radius=15;

    graphicsItemGroup->addToGroup(pixItem);

    this->setPos(200,400);

    this->setRandomDest();
}

void Bot::setRandomDest()
{
    dest.rx() = (QTime::currentTime().msec()*Bot::static_bot_rand)%600;
    dest.ry() = (QTime::currentTime().msec()*201*Bot::static_bot_rand)%600;

    creatureWish.rx() = dest.rx()-Creature::center().rx();
    creatureWish.ry() = dest.ry()-Creature::center().ry();

    updateAngle();
    Bot::static_bot_rand+=317;
}

void Bot::actualize()
{
    this->selfMove();
    if ( abs(Creature::center().rx()-dest.rx())<10
        && abs(Creature::center().ry()-dest.ry())<10 )
    {
        setRandomDest();
    }
}
