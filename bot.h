#ifndef BOT_H
#define BOT_H

#include "creature.h"

class Bot : public Creature
{
    //Q_OBJECT
public:
    Bot(QGraphicsScene * scene, QString impath);

    QImage *image;
    QGraphicsPixmapItem *pixItem;

    QPoint dest;
    void setRandomDest();
    void actualize() override;
    static int static_bot_rand;
};
#endif // BOT_H
