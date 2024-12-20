#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>

class GameView : public QGraphicsView
{
    Q_OBJECT
public:
    GameView(QWidget * parent);
    ~GameView();
    QGraphicsView * graphicsView;
};

#endif // GAMEVIEW_H
