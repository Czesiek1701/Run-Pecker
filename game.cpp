#include "game.h"
#include <QLayout>
#include "creature.h"
#include "gameboard.h"
#include "game.h"

Game::Game(QWidget * gamePageParent):
    running(false)
{
    centralWidget = nullptr;
    qDebug() << "Creating game...";
    gamePause = new GamePause(gamePageParent);
    gamePage = new GamePage(gamePageParent);
    centralWidget = gamePage;
    gamePage->setFocus();
    gameTimer = new QTimer(this);
    qDebug() << "Created game.";

    this->makeConnections();
    gameTimer->start(TIMESTAMP);
    //this->start();
}
Game::~Game()
{
    qDebug() << "Deleting game...";
    delete gamePage;
    delete gamePause;
    qDebug() << "Deleted game.";
}
void Game::start()
{
    running=true;
    gamePause->hide();
    gamePause->setParent(0);
    centralWidget = gamePage;
    emit s_update_central_vidget();
    gamePage->show();
    gamePage->setFocus();
    gameTimer->start();

}
void Game::pause()
{
    gameTimer->stop();
    running=false;
    qDebug()<<"Paused game";
    gamePage->hide();
    gamePage->setParent(0);
    centralWidget = gamePause;
    emit s_update_central_vidget();
    gamePause->show();
    gamePause->setFocus();
}

void Game::makeConnections()
{
    connect(
        gamePage,
        &GamePage::s_pause_game,
        this,
        &Game::pause
        );

    connect(
        gamePause,
        &GamePause::s_startGame,
        this,
        &Game::start
        );

    connect(
        gameTimer,
        &QTimer::timeout,
        this->gamePage->gameBoard,
        &GameBoard::updateCreatures
        );

    connect(
        gameTimer,
        &QTimer::timeout,
        this->gamePage,
        &GamePage::send_movement
        );

    // connect(
    //     this->gamePage,
    //     &GamePage::s_player_move_x,
    //     this->gamePage->gameBoard->creature,
    //     &Creature::setWishx
    //     );
    // connect(
    //     this->gamePage,
    //     &GamePage::s_player_move_y,
    //     this->gamePage->gameBoard->creature,
    //     &Creature::setWishy
    //     );
    connect(
        this->gamePage,
        &GamePage::s_player_movement,
        this->gamePage->gameBoard->player,
        &Player::getMovementWish
        );
}
// void Game::close()
// {
//     this->pause();
//     qDebug()<<"Close game";
// }
