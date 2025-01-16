#ifndef BOT_H
#define BOT_H

#include "creature.h"

class Bot : public Creature
{
    Q_OBJECT
public:
    Bot(QGraphicsScene * scene, QString impath);
    QPoint dest;
    void setRandomDest();
    void actualize() override;
};
#endif // BOT_H
