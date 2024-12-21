#ifndef CREATURE_H
#define CREATURE_H
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>

class Creature
{
    QImage *image;
    QGraphicsPixmapItem *pixItem;
    //QGraphicsScene *game_graphicsScene;
public:
    Creature(QGraphicsScene * scene);
    ~Creature();
    void creatureMove(int x, int y);
    QGraphicsPixmapItem *getPixItem();
};

#endif // CREATURE_H
