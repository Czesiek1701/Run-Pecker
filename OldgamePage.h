#ifndef OLDGAMEPAGE_H
#define OLDGAMEPAGE_H

#include <QWidget>
#include <QStackedLayout>
#include <QGraphicsView>
#include <QPushButton>

class OldGamePage : public QWidget
{
    //Q_OBJECT
public:
    OldGamePage(QWidget *parent);
    ~OldGamePage();
    QGraphicsView *qgv;

};

#endif // OLDGAMEPAGE_H
