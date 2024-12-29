#include "gamepage.h"
#include "ui_gamepage.h"

GamePage::GamePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GamePage)
{
    qDebug()<<"Creating GamePage";
    gamePause = new GamePause(parent);
    ui->setupUi(this);
    //this->show();
    //connect(gamePause,GamePause::s_exitGame(),this,GamePage::on_pushButton_clicked());
    qDebug()<<"Created GamePage";
}

GamePage::~GamePage()
{

    qDebug()<<"Deleting GamePage";
    delete gamePause;
    delete ui;
    qDebug()<<"Deleted GamePage";
}



void GamePage::on_pushButton_clicked()
{
    qDebug()<<"push clicked";
    gamePause->show();
}

