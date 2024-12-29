#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QGraphicsView>
#include "gamepause.h"
#include <QLayout>

namespace Ui {
class GamePage;
}

class GamePage : public QWidget
{
    Q_OBJECT

public:
    explicit GamePage(QWidget *parent = nullptr);
    ~GamePage();
    GamePause *gamePause;

private slots:
    void on_pushButton_clicked();

private:
    Ui::GamePage *ui;
};

#endif // GAMEPAGE_H
