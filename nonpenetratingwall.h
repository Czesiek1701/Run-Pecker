#ifndef NONPENETRATINGWALL_H
#define NONPENETRATINGWALL_H
#include "imapobject.h"
#include <QGraphicsRectItem>

class NonPenetratingWall : public IMapObject
{
public:
    NonPenetratingWall(QGraphicsScene * scene);

    QRectF qRectF;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    //QPainterPath shape() const override;

};

#endif // NONPENETRATINGWALL_H
