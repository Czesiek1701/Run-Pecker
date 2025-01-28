#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsObject>

class Background : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Background(QGraphicsScene *parent = nullptr);
    ~Background();

    QRectF renderBoundingRect;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    QGraphicsItemGroup *graphicsItemGroup;
    void addRectsGrid();


signals:
};

#endif // BACKGROUND_H
