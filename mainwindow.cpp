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
    ui->stackedWidget->setCurrentIndex(0);

    //ui->graphicsView->setBackgroundBrush(QBrush(Qt::yellow));

    //ui->graphicsView->show();

}

MainWindow::~MainWindow()
{
    qDebug()<<"MW destructor";
    delete ui;
}

void MainWindow::on_pushButton_NewGmae_clicked()
{
    ui->stackedWidget->setCurrentIndex(ePages::p_game);
    ui->pushButton_Play->setText("Play");

    game = nullptr;
    scene = new QGraphicsScene(this);
    ui->graphicsView->setBackgroundBrush(QBrush(Qt::gray));
    ui->graphicsView->setScene(scene);
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(ePages::p_start);
}


void MainWindow::on_pushButton_2_clicked()
{
    if(game!=nullptr) delete game;
    game = nullptr;
    //ui->graphicsView->items().remove(0,0);
    if(scene!=nullptr) delete scene;
    scene = nullptr;
    ui->graphicsView->show();
    ui->stackedWidget->setCurrentIndex(ePages::p_start);
    qDebug()<<"deleting";
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_R:
        qDebug()<<"key_R";
        MainWindow::ui->textEdit->setText("R clicked");
        break;
    default:
        MainWindow::ui->textEdit->setText("sth clicked");
        break;
    }

    // if(event->key() == Qt::Key_R)
    // {
    //     qDebug()<<"key_R";
    //     MainWindow::ui->textEdit->setText("R clicked");
    // }
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
        qDebug()<<"Game nullptr";

        scene->addItem(game->pixitem_pecker);
    }
    else
    {
        if (game->running==true)
        {
            qDebug()<<"Game running";
            game->running = false;
            ui->pushButton_Play->setText("Start");
        }
        else
        {
            qDebug()<<"Game not running";
            game->running = true;
            ui->pushButton_Play->setText("Pause");
        }
    }
    qDebug()<<"play clicked";
    qDebug()<<game;
    ui->textEdit->setText((game->running==true)?"true":"false");
}



void MainWindow::on_pushButton_refresh_clicked()
{
    if(game!=nullptr)
    {
        ui->textEdit->setText((game->running==true)?"true":"false");
    }
    else
    {
        ui->textEdit->setText("null");
    }
    ui->textEdit->show();
    qDebug()<<"click";

    if(game!=nullptr)
    {
        game->pixitem_pecker->setOffset(game->pixitem_pecker->offset()+QPoint(10,10));
    qDebug()<<"draw";
    }

    ui->graphicsView->show();
}



