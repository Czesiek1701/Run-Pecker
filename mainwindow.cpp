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
    //scene = new QGraphicsScene(this);
    //game_graphic_view = ui->graphicsView;
    //ui->graphicsView->setBackgroundBrush(QBrush(Qt::gray));
    //ui->graphicsView->setScene(scene);
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(ePages::p_start);

    //delete game_graphic_view; //podmiana
    //delete scene1;

    delete game;
}


void MainWindow::on_pushButton_2_clicked()
{
    if(game!=nullptr) delete game;
    game = nullptr;
    //ui->graphicsView->items().remove(0,0);
    //if(scene!=nullptr) delete scene;
    //scene = nullptr;
    //ui->graphicsView->show();
    ui->stackedWidget->setCurrentIndex(ePages::p_start);
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

    //game_graphic_view = new QGraphicsView(ui->pushButton->parentWidget()); //podmiana
    //game_graphic_view->setBackgroundBrush(QBrush(Qt::blue));
    // //ui->stackedWidget->show();
    // //ui->stackedWidget->stackUnder(ui->pushButton_9);

    // //ui->stackedWidget->insertWidget(ePages::p_settings,game_graphic_view);

    //game_graphic_view->setSceneRect(-100,-100,400,500);
    //game_graphic_view->move(000,000);
    // //game_graphic_view->stackUnder(ui->pushButton_9);
    // //game_graphic_view->Rect
    // //game_graphic_view->setScene(scene);

    game = new Game(ui->pushButton->parentWidget());
    game->gameView->stuckUnder(ui->pushButton);
    //scene1 = new QGraphicsScene(game_graphic_view);
    // //static QGraphicsRectItem rect = QGraphicsRectItem();
    // //rect.setRect(0,0,100,100);
    //scene1->addItem(game->pixitem_pecker);
    // //QRectF rect = (QRectF(0, 0, 100, 1000));
    // //scene1->addRect(rect);
    // //scene1->setSceneRect(100,100,300,300);
    // //scene1->setSceneRect(100,100,200,200);
    //game_graphic_view->setScene(scene1);

}


void MainWindow::on_pushButton_Close_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_Play_clicked()
{
    if (game == nullptr)
    {
        game = new Game(ui->stackedWidget->currentWidget());
        game -> gameView ->stuckUnder(ui->pushButton_2);
        ui->pushButton_Play->setText("Pause");
    }
    else
    {
        if (game->running==true)
        {
            qDebug()<<"Game running";
            game->pause();
            ui->pushButton_Play->setText("Start");
        }
        else
        {
            qDebug()<<"Game not running";
            game->start();
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
        game->pecker->creatureMove(10,10);
    qDebug()<<"draw";
    }

    //ui->graphicsView->show();
}



