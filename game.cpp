#include "game.h"

Game::Game():
    running(true)
{
    im_pecker = new QImage(":/data/pecker.bmp");
    pixitem_pecker = new QGraphicsPixmapItem(QPixmap::fromImage(*im_pecker));
}
Game::~Game()
{
    delete im_pecker;
    delete pixitem_pecker;
}
void Game::peckerMove(int x, int y)
{
    qDebug()<<"pecker move";
}
