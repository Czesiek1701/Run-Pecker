#include "background.h"
#include <QPainter>

Background::Background(QGraphicsScene *scene)
    : QGraphicsObject()
{
    qDebug()<<"Creating mapcontrol";
    scene->addItem(this);
    graphicsItemGroup = new QGraphicsItemGroup(this);
}

Background::~Background()
{
    qDebug()<<"Deleted mapcontrol";
}

QRectF Background::boundingRect() const
{
    return renderBoundingRect;
}

void Background::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawRect(50,50,30,30);


    painter->setBrush(Qt::blue);
    for(int i=-10; i<10; i++)
        for(int j=-10; j<10; j++)
        {
            QRectF rect = QRectF(100*i-2,100*j-2,4,4);
            painter->drawRect(rect);
        }
}

void Background::addRectsGrid()
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
