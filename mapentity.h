#ifndef NPOBJECT_H
#define NPOBJECT_H

#include <QGraphicsScene>
#include<QGraphicsObject>
#include <unordered_set>

#include "ibehaviourmanager.h"
#include "entityregistry.h"

//class EntityContainer;

class MapEntity : public QGraphicsObject
{
private:
    std::unordered_set<EntityRegistry*> managers;
public:
    MapEntity(QGraphicsScene * scene);
    virtual ~MapEntity();

    //QRectF boundingRectF;
    QGraphicsItemGroup *graphicsItemGroup;

    void insertManager(EntityRegistry*);
    void eraseManager(EntityRegistry*);
    //virtual QRectF boundingRect() const;
    //virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // NPOBJECT_H
