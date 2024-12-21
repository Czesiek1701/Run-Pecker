#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QStackedLayout>
#include <QGraphicsView>
#include <QPushButton>

class GamePage : public QWidget
{
    //Q_OBJECT
public:
    GamePage(QWidget *parent);
    ~GamePage();
    QGraphicsView *qgv;

};

#endif // GAMEPAGE_H
