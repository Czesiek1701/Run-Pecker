#include "gameboard.h"
#include <QBrush>

GameBoard::GameBoard(QWidget *parentView)
    : QGraphicsScene(parentView)
{
    qDebug()<<"Creating game board";
    mapControl = new MapControl(this);
    mapControl->setZValue(-100);

    player = new Player(this, ":/data/pecker.bmp");
    player->setZValue(1);
    creatures.push_back(player);

    // bot[0] = new Bot(this, ":/data/bot.bmp");
    // bot[1] = new Bot(this, ":/data/bot.bmp");
    // bot[2] = new Bot(this, ":/data/bot.bmp");
    for (int i=0;i<200;i++)
    {
        creatures.push_back(new Bot(this, ":/data/bot.bmp"));
        creatures[i+1]->setZValue(0);
    }
    qDebug()<<12;

    sceneRect = new QRectF(-200,-200,200,200);
    this->setSceneRect(*sceneRect);

    centerViewOnPlayer();

}


void GameBoard::updateCreatures()
{
    //player->actualize();
    for(Creature* c:creatures)
    {
        c->actualize();
    }

    centerViewOnPlayer();
}

void GameBoard::centerViewOnPlayer()
{
    // qDebaug()<<"centering";
    QGraphicsScene::setSceneRect(player->pos().rx()-100,player->pos().ry()-100,200,200);
    //QGraphicsView::translate(0,0);
}

// QGraphicsScene* GameBoard::getQGraphicsScene()
// {
//     return QGraphicsScene;
// };
