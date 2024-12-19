#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    scene = new QGraphicsScene(this);
}

MainWindow::~MainWindow()
{
    qDebug()<<"MW destructor";
    delete ui;
}

void MainWindow::on_pushButton_NewGmae_clicked()
{
    ui->stackedWidget->setCurrentIndex(ePages::p_game);
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(ePages::p_start);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(ePages::p_start);
}


void MainWindow::on_pushButton_Settings_clicked()
{
    ui->stackedWidget->setCurrentIndex(ePages::p_settings);
}


void MainWindow::on_pushButton_Close_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_Play_clicked()
{
    if (game == nullptr)
    {
        game = new Game();
        game->running = true;
        ui->pushButton_Play->setText("Pause");
    }
    else
    {
        if (game->running==true)
        {
            game->running = false;
            ui->pushButton_Play->setText("Start");
        }
        else
        {
            game->running = true;
            ui->pushButton_Play->setText("Pause");
        }
    }
    qDebug()<<"play clicked";
    ui->textEdit->setText((game->running==true)?"true":"false");
}


void MainWindow::on_pushButton_refresh_clicked()
{
    ui->textEdit->setText((game->running==true)?"true":"false");
    ui->textEdit->show();
    qDebug()<<"click";
}



