#ifndef NPOBJECT_H
#define NPOBJECT_H

#include <QGraphicsScene>
#include<QGraphicsObject>
#include <unordered_set>

#include "ibehaviourmanager.h"

class IBehaviourManager;

class MapEntity : public QGraphicsObject
{
private:
    std::unordered_set<IBehaviourManager*> managers;
public:
    MapEntity(QGraphicsScene * scene);
    virtual ~MapEntity();

    //QRectF boundingRectF;
    QGraphicsItemGroup *graphicsItemGroup;

    void insertManager(IBehaviourManager*);
    void eraseManager(IBehaviourManager*);
    //virtual QRectF boundingRect() const;
    //virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // NPOBJECT_H
