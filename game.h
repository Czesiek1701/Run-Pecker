#ifndef GAME_H
#define GAME_H
#include <QSharedData>
#include <QGraphicsPixmapItem>

class Game : public QSharedData
{
public:
    Game();
    ~Game();
    bool running;
    QImage* im_pecker;
    QGraphicsPixmapItem* pixitem_pecker;
    void peckerMove(int x, int y);
};

#endif // GAME_H
