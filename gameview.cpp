#include "gameview.h"

GameView::GameView(QWidget * parent)
{
    qDebug() << "Creating GameView...";
    graphicsView = new QGraphicsView(parent);
    graphicsScene = new QGraphicsScene(graphicsView);
    graphicsView->setScene(graphicsScene);
    graphicsView->setSceneRect(0,0,300,300);
    //game_graphic_view->stackUnder(graphicsScene->parent()->parent()->objectName());
    graphicsView->show();
    qDebug() << "Created GameView.";
}
GameView::~GameView()
{
    qDebug() << "Deleting GameView...";
    delete graphicsScene;
    delete graphicsView;
    qDebug() << "Deleted GameView.";
}
void GameView::stuckUnder(QWidget *ob)
{
    graphicsView->stackUnder(ob);
}
