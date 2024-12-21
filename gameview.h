#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>

class GameView
{
public:
    GameView(QWidget * parent);
    ~GameView();
    QGraphicsView * graphicsView;
    QGraphicsScene * graphicsScene;
    void stuckUnder(QWidget *ob);
};

#endif // GAMEVIEW_H
