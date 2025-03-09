#include "gameboarddirector.h"

GameBoardDirector::GameBoardDirector(QWidget* pv) {} // not used yet

GameBoard* GameBoardDirector::buildForPerformanceTest(QWidget* pv)
{
    GameBoardBuilder gbb(pv);
    gbb.setPlayer();
    gbb.addBot(50); // !!!!

    gbb.addWall(QPointF(-100,-100));
    gbb.addWall(QPointF(200,300));
    gbb.addWall(QPointF(400,800));
    gbb.addWall(QPointF(700,400));
    for (int i=0; i<100; i++) // !!!!
    {
        gbb.addWall(QPointF(-100,i*100));
        gbb.addWall(QPointF(i*100,-100));
        gbb.addWall(QPointF(900,i*100));
        gbb.addWall(QPointF(i*100,900));
    }

    return gbb.build();
}

GameBoard* GameBoardDirector::buildForManualTest(QWidget* pv)
{
    GameBoardBuilder gbb(pv);
    gbb.setPlayer();
    gbb.addBot(10); // !!!!

    gbb.addWall(QPointF(-100,-100));
    gbb.addWall(QPointF(200,300));
    gbb.addWall(QPointF(400,800));
    gbb.addWall(QPointF(700,400));
    for (int i=0; i<10; i++) // !!!!
    {
        gbb.addWall(QPointF(-100,i*100));
        gbb.addWall(QPointF(i*100,-100));
        gbb.addWall(QPointF(900,i*100));
        gbb.addWall(QPointF(i*100,900));
    }

    return gbb.build();
}

