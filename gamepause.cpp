#include "gamepause.h"
#include "ui_gamepause.h"

GamePause::GamePause(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GamePause)
{

    qDebug()<<"Creating GamePause";
    ui->setupUi(this);
    this->hide();
    qDebug()<<"CreatedGamePause";
}

GamePause::~GamePause()
{
    qDebug()<<"Deleting GamePause";
    delete ui;
    qDebug()<<"DeletedGamePause";
}

void GamePause::on_pushButton_Start_clicked()
{
    this->hide();
}


void GamePause::on_pushButton_Exit_clicked()
{
    qDebug()<<"game exit";
    //this->hide();
    emit s_exitGame();
}

