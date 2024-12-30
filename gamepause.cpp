#include "gamepause.h"
#include "ui_gamepause.h"
#include <QKeyEvent>

GamePause::GamePause(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GamePause)
{

    qDebug()<<"Creating GamePause";
    ui->setupUi(this);
    this->hide();
    qDebug()<<"Created GamePause";
}

GamePause::~GamePause()
{
    qDebug()<<"Deleting GamePause";
    delete ui;
    qDebug()<<"Deleted GamePause";
}

void GamePause::keyPressEvent(QKeyEvent *event)
{
    // switch (event->key())
    // {
    // case Qt::Key_R:
    //     qDebug()<<"key_R";
    //     break;
    // default:
    //     qDebug()<<"sth clicked";
    //     break;
    // }

    if(event->key() == Qt::Key_P)
    {
        qDebug()<<"P clicked";
        emit s_startGame();
    }
}

void GamePause::on_pushButton_Start_clicked()
{
    qDebug()<<"game start";
    emit s_startGame();
}


void GamePause::on_pushButton_Exit_clicked()
{
    qDebug()<<"game exit";
    //this->hide();
    emit s_exitGame();
}

