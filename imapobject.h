#ifndef NPOBJECT_H
#define NPOBJECT_H
#include <QGraphicsScene>
#include<QGraphicsObject>

class IMapObject : public QGraphicsObject
{
public:
    IMapObject(QGraphicsScene * scene);
    virtual ~IMapObject();

    //QRectF boundingRectF;
    QGraphicsItemGroup *graphicsItemGroup;
    //virtual QRectF boundingRect() const;
    //virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // NPOBJECT_H
