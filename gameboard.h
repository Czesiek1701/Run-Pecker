#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsView>
#include "creature.h"
#include <QGraphicsScene>
#include "player.h"
#include "bot.h"
#include <vector>
#include "background.h"
#include "nonpenetratingwall.h"
#include <QTransform>
#include "nonpenetrationmanager.h"
#include "playerfightmanager.h"

class GameBoard : public QGraphicsScene
{
    Q_OBJECT

    QRectF sceneViewRect;
    QRectF sceneRenderRect;

    NonPenetrationManager nonPenetrationManager;
    PlayerFightManager playerFightManager;

    Background *background;
    std::vector<Creature*> creatures;
    std::vector<NonPenetratingWall*> fixedObjects;

    void createPlayer();
    void createWalls();
    void createBots();
    void setUpViewRect();


public:
    GameBoard(QWidget* parentView);
    ~GameBoard() {}

    Player *player;
    void removeCreature(MapEntity*);
    void actualizeSceneRect();


public slots:
    void doStep();
};

#endif // GAMEBOARD_H
