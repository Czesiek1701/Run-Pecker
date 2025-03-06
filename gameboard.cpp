#include "gameboard.h"
#include <QBrush>

GameBoard::GameBoard(QWidget *parentView)
    : QGraphicsScene(parentView)
{
    qDebug()<<"Creating game board";

    playerFightManager.pGB=this;

    background = new Background(this);

    createPlayer();

    createBots();

    createWalls();

    setUpViewRect();
}

void GameBoard::doStep()
{
    contactManager.handle();

    playerFightManager.handle();

    for(Creature* c:creatures)
    {
        c->actualize();
    }

    actualizeSceneRect();
}

void GameBoard::createPlayer()
{
    player = new Player(this);
    creatures.push_back(player);

    contactManager.addMovable(player);
    playerFightManager.setPlayer(player);
}

void GameBoard::createBots()
{
    for (int i=0;i<5;i++)
    {
        creatures.push_back(new Bot(this));
        contactManager.addMovable(*(creatures.end()-1));
        playerFightManager.addMovable(*(creatures.end()-1));
    }
}

void GameBoard::createWalls()
{
    // temporary
    fixedObjects.push_back( new NonPenetratingWall(this, QRectF(0,0,100,1000)) );
    (*(fixedObjects.end()-1))->setPos(-200,-200);
    contactManager.addStable(*(fixedObjects.end()-1));
    fixedObjects.push_back( new NonPenetratingWall(this, QRectF(0,0,1000,100)) );
    (*(fixedObjects.end()-1))->setPos(-200,-200);
    contactManager.addStable(*(fixedObjects.end()-1));
    fixedObjects.push_back( new NonPenetratingWall(this, QRectF(0,0,100,1200)) );
    (*(fixedObjects.end()-1))->setPos(800,-200);
    (*(fixedObjects.end()-1))->setRotation(30);
    contactManager.addStable(*(fixedObjects.end()-1));
    fixedObjects.push_back( new NonPenetratingWall(this, QRectF(0,0,1200,100)) );
    (*(fixedObjects.end()-1))->setPos(-200,800);
    contactManager.addStable(*(fixedObjects.end()-1));
}

void GameBoard::setUpViewRect()
{
    sceneViewRect = QRectF(0,0,850*2,400*2);
    background->renderBoundingRect = QRectF(0,0,
                                            (int)(sceneViewRect.width()*1.1),
                                            (int)(sceneViewRect.height()*1.1)
                                            );
    actualizeSceneRect();
}

void GameBoard::actualizeSceneRect()
{
    //QPointF c=player->mapToScene( player->transformOriginPoint() );
    //QPointF c=player->center();

    sceneViewRect.moveCenter(player->center());
    this->setSceneRect(sceneViewRect);

    background->renderBoundingRect.moveCenter(player->center());
}

void GameBoard::removeCreature(Creature* c)
{
    creatures.erase(std::remove(creatures.begin(), creatures.end(), c), creatures.end());
}
