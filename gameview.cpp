#include "gameview.h"

GameView::GameView(QWidget * parent)
{
    graphicsView = new QGraphicsView(parent);
}
GameView::~GameView()
{
    delete graphicsView;
}
