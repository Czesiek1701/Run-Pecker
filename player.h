#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "creature.h"
#include <QPainter>

class Player : public Creature
{
    //Q_OBJECT
public:
    explicit Player(QGraphicsScene * scene, QString impath);

    QImage *image;
    QGraphicsPixmapItem *pixItem;

public slots:
    void getMovementWish(std::bitset<16> pressed);
signals:
};

#endif // PLAYER_H
