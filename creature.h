#ifndef CREATURE_H
#define CREATURE_H
#include <QGraphicsObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPoint>
#include <bitset>
#include <cmath>

extern int TIMESTAMP;
extern double PI;

class Creature : public QGraphicsObject
{
    //Q_OBJECT
public:
    Creature(QGraphicsScene * scene);
    ~Creature();
    //QGraphicsPixmapItem *pixItem;
    //QImage *image;
    QRectF boundingRectF;
    QGraphicsItemGroup *graphicsItemGroup;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    //QGraphicsPixmapItem *pixItem;
    //QGraphicsScene *game_graphicsScene;
    void creatureMove(int x, int y);
    //QGraphicsPixmapItem *getPixItem();
    int creatureWish[2] = {0,0};
    void selfMove();
    void updateAngle();
    int vel = 300; //  pix/s
    int step = int( (TIMESTAMP/1000.0)*vel) ;
public slots:
    void creatureDummyMove();
    virtual void actualize();
    //void setWishx(int d);
    //void setWishy(int d);
    //void getMovementWish(std::bitset<16>);
};

#endif // CREATURE_H
