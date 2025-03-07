#ifndef CREATURE_H
#define CREATURE_H
#include <QGraphicsObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPoint>
#include <bitset>
#include <cmath>
#include "mapentity.h"

extern const int TIMESTAMP;
extern double PI;

class Creature : public MapEntity
{

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

    void selfMove( );
    void updateAngle();

    qreal contact_radius=10; //default

    void handleContact(const QGraphicsItem& fixObj);

public slots:
    virtual void actualize();
    //void setWishx(int d);
    //void setWishy(int d);
    //void getMovementWish(std::bitset<16>);
};

#endif // CREATURE_H
