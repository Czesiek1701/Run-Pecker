#include "gameboard.h"
#include <QBrush>

GameBoard::GameBoard(QWidget *parentView)
    : QGraphicsScene(parentView)
{
    player = new Player(this, ":/data/pecker.bmp");
    player->setZValue(1);
    creatures.push_back(player);
    // bot[0] = new Bot(this, ":/data/bot.bmp");
    // bot[1] = new Bot(this, ":/data/bot.bmp");
    // bot[2] = new Bot(this, ":/data/bot.bmp");
    for (int i=0;i<10;i++)
    {
        creatures.push_back(new Bot(this, ":/data/bot.bmp"));
        creatures[i+1]->setZValue(0);
    }
    qDebug()<<12;

    sceneRect = new QRectF(-100,-100,100,100);
    this->setSceneRect(*sceneRect);

    centerViewOnPlayer();

    QGraphicsRectItem* rect = new QGraphicsRectItem(-10,-10,20,20);
    rect->setBrush(Qt::blue);
    this->addItem(rect);


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
}

// QGraphicsScene* GameBoard::getQGraphicsScene()
// {
//     return QGraphicsScene;
// };
