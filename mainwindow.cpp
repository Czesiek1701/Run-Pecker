#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

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
    this->setCentralWidget(game);


    QObject::connect(
        this->game->gamePause,
        &GamePause::s_exitGame,
        this,
        &MainWindow::close_game
    );
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


void MainWindow::close_game()
{
    qDebug()<<"closing game";
    if (game != nullptr)
    {
        delete game;
        game = nullptr;
    }
    qDebug()<<ui;
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->page_start);
    qDebug()<<ui;
    this->setFocus();
}

void MainWindow::on_pushButton_Back_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_start);
}

