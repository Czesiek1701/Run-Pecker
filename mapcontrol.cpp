#include "mapcontrol.h"

MapControl::MapControl(QGraphicsScene *scene)
    : QGraphicsObject()
{
    qDebug()<<"Creating mapcontrol";
    scene->addItem(this);
    graphicsItemGroup = new QGraphicsItemGroup(this);

    addRectsGrid();
}

MapControl::~MapControl()
{
    qDebug()<<"Deleting mapcontrol";
}

QRectF MapControl::boundingRect() const
{
    //return pixItem -> boundingRect();
    return QRectF();
}

void MapControl::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);
}

void MapControl::addRectsGrid()
{
    for(int i=-10; i<10; i++)
        for(int j=-10; j<10; j++)
            {
                QGraphicsRectItem* rect = new QGraphicsRectItem(-2,-2,4,4,this);
                rect->setPos(i*100,j*100);
                rect->setBrush(Qt::darkMagenta);
                graphicsItemGroup->addToGroup(rect);
            }
}
