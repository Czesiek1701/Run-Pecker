#include "game.h"
#include <QLayout>
#include "creature.h"
#include "gameboard.h"
#include "game.h"

const int TIMESTAMP = 1000/120; // 1000[ms]/x[Hz]

// map, map cell, map save, map background, colliding object, egg,

Game::Game(QWidget * gamePageParent):
    running(false),
    QWidget(gamePageParent)
{
    this->setObjectName("game");

    qDebug() << "Creating game... ";

    stackedLayout = new QStackedLayout(this);
    stackedLayout->setStackingMode(QStackedLayout::StackAll);
    this->setLayout(stackedLayout);

    gamePage = new GamePage(this);
    stackedLayout->addWidget(gamePage);

    gamePause = new GamePause(this);
    stackedLayout->addWidget(gamePause);

    gamePage->setFocus();
    gameTimer = new QTimer(this);

    makeGamePageConnections();
    makeGamePauseConnections();

    gameTimer->start(TIMESTAMP);

    qDebug() << "Created game.";
}
Game::~Game()
{
    qDebug() << "Deleting game...";
}
void Game::start()
{
    qDebug()<<"Starting game";

    running=true;

    gamePause->hide();

    gamePage->showMaximized();
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
        &GameBoard::doStep
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
        &GameBoard::actualizeSceneRect
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
