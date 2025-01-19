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
        on_pushButton_gpPause_clicked();
        break;
    case Qt::Key_D:
        pressed[3]=true;
        break;
    case Qt::Key_A:
        pressed[1]=true;
        break;
    case Qt::Key_W:
        pressed[0]=true;
        break;
    case Qt::Key_S:
        pressed[2]=true;
        break;
    case Qt::Key_B:
        qDebug()<<"B key";
        //qDebug()<<gameBoard->player->pos();
        emit emit_b();
        //ui->boardView->centerOn(gameBoard->player->pos());
        //ui->boardView->fitInView( QRectF( gameBoard->player->boundingRect() ) );
        //ui->boardView->centerOn( gameBoard->player->pos() );
        //ui->boardView->ensureVisible(gameBoard->player->boundingRect(),50,50);
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
        pressed[3]=false;
        break;
    case Qt::Key_A:
        pressed[1]=false;
        break;
    case Qt::Key_W:
        pressed[0]=false;
        break;
    case Qt::Key_S:
        pressed[2]=false;
        break;
    default:
        break;
    }
}

void GamePage::send_movement()
{
    emit s_player_movement(pressed);
    //ui->boardView->translate( 100,100 );
}

void GamePage::on_pushButton_gpPause_clicked()
{
    pressed.reset();
    send_movement();
    emit s_pause_game();
}

