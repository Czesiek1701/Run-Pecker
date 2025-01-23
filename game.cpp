#include "game.h"
#include <QLayout>
#include "creature.h"
#include "gameboard.h"
#include "game.h"

// map, map cell, map save, map background, colliding object, egg,

Game::Game(QWidget * gamePageParent):
    running(false),
    QWidget(gamePageParent)
{
    qDebug() << "Creating game...";
    gamePage = new GamePage(this);
    //setHeightForWidth()

    gamePause = new GamePause(this);
    makeGamePauseConnections();
    //center policy

    gamePage->setFocus();
    gameTimer = new QTimer(this);
    qDebug() << "Created game.";

    this->makeGamePageConnections();
    gameTimer->start(TIMESTAMP);
}
Game::~Game()
{
    qDebug() << "Deleting game...";
    // delete gamePage;
    // delete gamePause;
    //emit game_close();
    //qDebug() << "Deleted game.";
}
void Game::start()
{
    qDebug()<<"Starting game";

    running=true;

    gamePause->hide();

    gamePage->show();
    gamePage->setFocus();
    gamePage->raise();

    gameTimer->start();

}
void Game::pause()
{
    qDebug()<<"Pausing game";

    gameTimer->stop();

    running=false;

    gamePause->show();
    gamePause->setFocus();
    gamePause->raise();
}

void Game::makeGamePageConnections()
{
    connect(
        gamePage,
        &GamePage::s_pause_game,
        this,
        &Game::pause
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
    connect(
        this->gamePage,
        &GamePage::s_player_movement,
        this->gamePage->gameBoard->player,
        &Player::getMovementWish
        );
    connect(
        this->gamePage,
        &GamePage::emit_b,
        this->gamePage->gameBoard,
        &GameBoard::centerViewOnPlayer
        );
}


void Game::makeGamePauseConnections()
{
    connect(
        gamePause,
        &GamePause::s_startGame,
        this,
        &Game::start
        );
}
