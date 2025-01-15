#ifndef CREATURE_H
#define CREATURE_H
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPoint>
#include <bitset>

extern int TIMESTAMP;

class Creature : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Creature(QGraphicsScene * scene);
    ~Creature();
    QImage *image;
    //QGraphicsPixmapItem *pixItem;
    //QGraphicsScene *game_graphicsScene;
    void creatureMove(int x, int y);
    //QGraphicsPixmapItem *getPixItem();
    int creatureWish[2] = {0,0};
    void selfMove();
    int vel = 300; //  pix/s
    int step = int( (TIMESTAMP/1000.0)*vel) ;
    void rotateAroundCenter(int angles);
public slots:
    void creatureDummyMove();
    //void setWishx(int d);
    //void setWishy(int d);
    void getMovementWish(std::bitset<16>);
};

#endif // CREATURE_H
