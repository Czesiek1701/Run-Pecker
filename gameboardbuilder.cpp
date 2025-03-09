#include "gameboardbuilder.h"


GameBoardBuilder::GameBoardBuilder(QWidget* pV)
{
    productGB = new GameBoard(pV);
}

GameBoard* GameBoardBuilder::build()
{
    if(productGB->player == nullptr)
    {
        qDebug() << "player nullptr";
        this->setPlayer();
    }
    else
    {
        qDebug() << "player was not nullptr";
        qDebug() << productGB->player;
    }
    //productGameBoard->createPlayer();
    productGB->setUpViewRect();

    return productGB;
}

GameBoardBuilder& GameBoardBuilder::setPlayer()
{
    productGB->createPlayer();

    return *this;
}

GameBoardBuilder& GameBoardBuilder::addBot()
{
    productGB->createBot();

    return *this;
}

GameBoardBuilder& GameBoardBuilder::addBot(int nob)
{
    for(int i=0; i<nob; i++)
    {
        productGB->createBot();
    }
    return *this;
}

GameBoardBuilder& GameBoardBuilder::addWall()
{
    productGB->createWall(QPointF(-100,-100),QRectF(0,0,100,100));

    return *this;
}

GameBoardBuilder& GameBoardBuilder::addWall(QPointF qpf)
{
    productGB->createWall(qpf,QRectF(0,0,100,100));

    return *this;
}

