#ifndef MAPCONTROL_H
#define MAPCONTROL_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsObject>

class MapControl : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit MapControl(QGraphicsScene *parent = nullptr);
    ~MapControl();

    QRectF renderBoundingRect;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    QGraphicsItemGroup *graphicsItemGroup;
    void addRectsGrid();


signals:
};

#endif // MAPCONTROL_H
