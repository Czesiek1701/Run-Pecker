#include "gameboard.h"
#include <QBrush>
#include "gameboardbuilder.h"

GameBoard::GameBoard(QWidget *parentView)
    : QGraphicsScene(parentView), playerFightManager(this)
{
    qDebug()<<"Creating game board";

    background = new Background(this);

    //createPlayer();

    //createBot();

    //createWall(QPointF(-100,-100),QRectF(0,0,100,100));

    //setUpViewRect();
}

GameBoardBuilder GameBoard::create(QWidget* pV)
{
    return GameBoardBuilder(pV);
}

void GameBoard::doStep()
{
    nonPenetrationManager.handle();

    playerFightManager.handle();

    for(Creature* c:creatures)
    {
        c->actualize();
    }

    actualizeSceneRect();
}

Player* GameBoard::createPlayer()
{
    player = new Player(this);
    creatures.push_back(player);

    //contactManager.addMovable(player);
    nonPenetrationManager.mmovables.add(player);
    playerFightManager.setPlayer(player);

    return player;
}

Bot* GameBoard::createBot()
{
    //for (int i=0;i<5;i++)
    //{
    creatures.push_back(new Bot(this));
    //contactManager.addMovable(*(creatures.end()-1));
    nonPenetrationManager.mmovables.add(*(creatures.end()-1));
    //playerFightManager.addMovable(*(creatures.end()-1));
    playerFightManager.mmovables.add(*(creatures.end()-1));
    //}
    return (Bot*)*creatures.end();
}

NonPenetratingWall* GameBoard::createWall(QPointF qpf = QPointF(-100,-100), QRectF qrf = QRectF(0,0,100,100))
{
    // temporary
    fixedObjects.push_back( new NonPenetratingWall(this, qrf) );
    (*(fixedObjects.end()-1))->setPos(qpf);
    nonPenetrationManager.mstables.add(*(fixedObjects.end()-1));
    // fixedObjects.push_back( new NonPenetratingWall(this, QRectF(0,0,1000,100)) );
    // (*(fixedObjects.end()-1))->setPos(-200,-200);
    // // contactManager.addStable(*(fixedObjects.end()-1));
    // nonPenetrationManager.mstables.add(*(fixedObjects.end()-1));
    // fixedObjects.push_back( new NonPenetratingWall(this, QRectF(0,0,100,1200)) );
    // (*(fixedObjects.end()-1))->setPos(800,-200);
    // (*(fixedObjects.end()-1))->setRotation(30);
    // // contactManager.addStable(*(fixedObjects.end()-1));
    // nonPenetrationManager.mstables.add(*(fixedObjects.end()-1));
    // fixedObjects.push_back( new NonPenetratingWall(this, QRectF(0,0,1200,100)) );
    // (*(fixedObjects.end()-1))->setPos(-200,800);
    // // contactManager.addStable(*(fixedObjects.end()-1));
    // nonPenetrationManager.mstables.add(*(fixedObjects.end()-1));

    return *fixedObjects.end();
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

void GameBoard::removeCreature(MapEntity* c)
{
    creatures.erase(std::remove(creatures.begin(), creatures.end(), c), creatures.end());
}
