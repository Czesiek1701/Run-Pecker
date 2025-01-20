#include "mapcontrol.h"
#include <QPainter>

// class MyRect: public QGraphicsRectItem
// {
// public:
//     MyRect(qreal x1,qreal x2,qreal x3,qreal x4, QGraphicsObject* parent)
//         : QGraphicsRectItem(x1,x2,x3,x4,parent)
//     {

//     }
//     ~MyRect()
//     {
//         qDebug()<<"deleted myRect";
//     }
// };

MapControl::MapControl(QGraphicsScene *scene)
    : QGraphicsObject()
{
    qDebug()<<"Creating mapcontrol";
    scene->addItem(this);
    graphicsItemGroup = new QGraphicsItemGroup(this);

    //addRectsGrid();
}

MapControl::~MapControl()
{

    delete graphicsItemGroup;
    qDebug()<<"Deleted mapcontrol";
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
    //Q_UNUSED(painter);
    painter->drawRect(50,50,30,30);


    painter->setBrush(Qt::blue);
    for(int i=-10; i<10; i++)
        for(int j=-10; j<10; j++)
        {
            QRectF rect = QRectF(100*i-2,100*j-2,4,4);
            //rect.setPos(i*100,j*100);
            //rect.setBrush(Qt::darkMagenta);
            painter->drawRect(rect);
        }
}

void MapControl::addRectsGrid()
{
    for(int i=-10; i<10; i++)
        for(int j=-10; j<10; j++)
            {
                QGraphicsRectItem rect = QGraphicsRectItem(-2,-2,4,4,this);
                rect.setPos(i*100,j*100);
                rect.setBrush(Qt::darkMagenta);
                graphicsItemGroup->addToGroup(&rect);
            }
}
