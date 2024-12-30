#include "gamepage.h"
#include "ui_gamepage.h"

GamePage::GamePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GamePage)
{
    qDebug()<<"Creating GamePage";
    //gamePause = new GamePause(parent);
    ui->setupUi(this);
    this->show();

    ui->boardView->setBackgroundBrush(QBrush(Qt::darkGreen));

    //ui->boardView->setSceneRect(0,0,500,500);
    gameBoard = new GameBoard(ui->boardView);
    ui->boardView->setScene((QGraphicsScene*)gameBoard);
    //gameScene->setSceneRect(0,0,400,400);
    //pecker = new Creature((QGraphicsScene*)gameBoard);
    //pecker -> creatureMove(100,100);
    //connect(gamePause,GamePause::s_exitGame(),this,GamePage::on_pushButton_clicked());
    qDebug()<<"Created GamePage";
}

GamePage::~GamePage()
{

    qDebug()<<"Deleting GamePage";
    //delete gamePause;
    delete ui;
    qDebug()<<"Deleted GamePage";
}

void GamePage::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_P:
        emit s_pause_game();
    case Qt::Key_D:
        emit s_player_move_x(1);
        break;
    case Qt::Key_A:
        emit s_player_move_x(-1);
        break;
    case Qt::Key_W:
        emit s_player_move_y(-1);
        break;
    case Qt::Key_S:
        emit s_player_move_y(1);
        break;
    default:
        break;
    }
}

void GamePage::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_D:
        qDebug()<<"D relesed";
        emit s_player_move_x(0);
        break;
    case Qt::Key_A:
        emit s_player_move_x(0);
        break;
    case Qt::Key_W:
        emit s_player_move_y(0);
        break;
    case Qt::Key_S:
        emit s_player_move_y(0);
        break;
    default:
        qDebug()<<"sth relesed";
        break;
    }
}

void GamePage::on_pushButton_gpPause_clicked()
{
    qDebug()<<"push clicked";
    emit s_pause_game();
    //gamePause->show();
}

