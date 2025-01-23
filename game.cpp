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
    qLayoutS = new QBoxLayout(QBoxLayout::Down, this);
    qLayoutG = new QBoxLayout(QBoxLayout::Down, this);
    qLayoutG->setSpacing(0);
    qLayoutS->setSpacing(0);

    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //this->frameSize();
    this->adjustSize();

    qDebug() << "Creating game...";
    gamePage = new GamePage(this);
    qLayoutG->addWidget(gamePage);
    //gamePage->mapToParent();

    gamePause = new GamePause(this);
    makeGamePauseConnections();
    qLayoutS->addWidget(gamePause);
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

    gamePage->showMaximized();
    gamePage->setFocus();
    gamePage->raise();

    //this->setLayout(qLayoutG);

    gameTimer->start();

}
void Game::pause()
{
    qDebug()<<"Pausing game";

    gameTimer->stop();

    running=false;

    this->setLayout(qLayoutS);

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
