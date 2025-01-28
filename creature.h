#ifndef CREATURE_H
#define CREATURE_H
#include <QGraphicsObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPoint>
#include <bitset>
#include <cmath>
#include "imapobject.h"

extern int TIMESTAMP;
extern double PI;

class Creature : public IMapObject
{
    //Q_OBJECT
public:
    Creature(QGraphicsScene * scene);
    virtual ~Creature();

    QRectF boundingRectF;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    QPointF center();
    QPoint creatureWish = {0,0};
    int vel = 300; //  pix/s
    int step = int(TIMESTAMP*vel/1000.0);

    void selfMove();
    void updateAngle();

public slots:
    virtual void actualize();
    //void setWishx(int d);
    //void setWishy(int d);
    //void getMovementWish(std::bitset<16>);
};

#endif // CREATURE_H
