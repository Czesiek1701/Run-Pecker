#ifndef NONPENETRATINGWALL_H
#define NONPENETRATINGWALL_H
#include "mapentity.h"
#include <QGraphicsRectItem>

class NonPenetratingWall : public MapEntity
{
public:
    NonPenetratingWall(QGraphicsScene * scene);
    NonPenetratingWall(QGraphicsScene * scene, QRectF);

    QRectF qRectF;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    //QPainterPath shape() const override;

};

#endif // NONPENETRATINGWALL_H
