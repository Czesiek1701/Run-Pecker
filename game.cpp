#include "game.h"

Game::Game(QWidget * parent):
    running(false)
{
    qDebug() << "Creating game...";
    gameView = new GameView(parent);
    pecker = new Creature(gameView->graphicsScene);
    qDebug() << "Created game.";
}
Game::~Game()
{
    qDebug() << "Deleting game...";
    delete pecker;
    delete gameView;
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
