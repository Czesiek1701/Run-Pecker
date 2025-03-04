#include "nonpenetratingwall.h"
#include "qpainter.h"

NonPenetratingWall::NonPenetratingWall(QGraphicsScene * scene)
    : IMapObject(scene)
{
    this->setObjectName("wall");

    qDebug() << "Creating NonPenWall";
    qRectF = QRectF(0,0,300,300);
    this->setRotation(30);
    //graphicsItemGroup -> addToGroup(qgRectItem);
    //qDebug() << shape();
    //qDebug() << mapToScene(shape());
}


NonPenetratingWall::NonPenetratingWall(QGraphicsScene * scene, QRectF qrf)
    : IMapObject(scene)
{
    this->setObjectName("wall");

    qDebug() << "Creating NonPenWall";
    qRectF = qrf;
    //this->setRotation(qRectF.width()*2+qRectF.height()*3);
}

// QPainterPath NonPenetratingWall::shape() const
// {
//     QPainterPath path;
//     path.addRect((this->boundingRect()));
//     return path;
// }

QRectF NonPenetratingWall::boundingRect() const
{
    return qRectF;
}

void NonPenetratingWall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);


    painter->setBrush(Qt::gray);
    painter->drawRect(qRectF);
}
