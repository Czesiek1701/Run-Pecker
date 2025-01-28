#include "gamepage.h"
#include "ui_gamepage.h"

GamePage::GamePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GamePage)
{
    qDebug()<<"Creating GamePage";

    ui->setupUi(this);
    this->show();

    ui->boardView->setBackgroundBrush(QBrush(Qt::darkGreen));

    gameBoard = new GameBoard(ui->boardView);
    ui->boardView->setScene((QGraphicsScene*)gameBoard);

    ui->boardView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->boardView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->boardView->setRenderHint(QPainter::Antialiasing);

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
        emit emit_b();
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
    ui->boardView->fitInView(gameBoard->sceneRect(),Qt::KeepAspectRatioByExpanding);
    // limit that view!
}

void GamePage::on_pushButton_gpPause_clicked()
{
    //pressed.reset();
    //send_movement();
    emit s_pause_game();
}

