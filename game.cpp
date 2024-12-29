#include "game.h"

Game::Game(QWidget * gamePageParent):
    running(false)
{
    qDebug() << "Creating game...";
    gamePage = new GamePage(gamePageParent);

    qDebug() << "Created game.";
}
Game::~Game()
{
    qDebug() << "Deleting game...";
    delete gamePage;
    qDebug() << "Deleted game.";
}
void Game::start()
{
    running=true;
    emit game_start();
}
void Game::pause()
{
    running=false;
    emit game_pause();
}
// void Game::close()
// {
//     this->pause();
//     qDebug()<<"Close game";
// }
