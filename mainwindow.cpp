#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
// #include "gamepause.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->hide();
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    qDebug()<<"MW destructor";
    delete ui;
}

void MainWindow::on_pushButton_NewGmae_clicked()
{
    qDebug()<<"clicked NewGame";
    game = new Game(this);
    this->updateCentralWidget();
    //game->gamePage->gamePause->show();

    QObject::connect(
        this->game->gamePause,
        &GamePause::s_exitGame,
        this,
        &MainWindow::close_game
        );

    QObject::connect(
        this->game,
        &Game::s_update_central_vidget,
        this,
        &MainWindow::updateCentralWidget
        );

}

void MainWindow::updateCentralWidget()
{
    if (game)
    {
        this->setCentralWidget(game->centralWidget);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(game!=nullptr) delete game;
    ui->stackedWidget->setCurrentIndex(ePages::p_start);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_R:
        qDebug()<<"key_R";
        break;
    default:
        qDebug()<<"sth clicked";
        break;
    }

    if(event->key() == Qt::Key_R)
    {
        qDebug()<<"key_R if";
    }
}

void MainWindow::on_pushButton_Settings_clicked()
{
    ui->stackedWidget->setCurrentIndex(ePages::p_settings);

}


void MainWindow::on_pushButton_Close_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_5_clicked()
{

}

void MainWindow::close_game()
{
    qDebug()<<"closing game";
    if (game != nullptr)
    {
        //game->close();
        delete game;
        game = nullptr;
    }
    qDebug()<<ui;
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->page_start);
    qDebug()<<ui;
    this->setFocus();
    //this->focusWidget();
    //this->setCentralWidget(this);
    //ui->stackedWidget->show();
    //this->takeCentralWidget();
    //ui->stackedWidget->setCurrentWidget(ui->page_start);
    //ui->stackedWidget->show();

}

void MainWindow::on_pushButton_clicked()
{
}


void MainWindow::on_pushButton_Back_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_start);
}

