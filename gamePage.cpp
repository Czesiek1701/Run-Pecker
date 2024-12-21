#include "gamePage.h"

GamePage::GamePage(QWidget *parent) : QWidget(parent)
{
    qDebug()<<"Creating GamePage...";
    qgv = new QGraphicsView(this);
    qgv->setBackgroundBrush(QBrush(Qt::yellow));
    qgv->setSceneRect(0,0,100,100);
    qgv->show();
    qDebug()<<"Created GamePage.";
};
GamePage::~GamePage()
{
    qDebug()<<"Deleting GamePage...";
    QWidget::~QWidget();
    qDebug()<<"Deleted GamePage.";
}
