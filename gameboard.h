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

class GameBoardBuilder;

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

    Player* createPlayer();
    NonPenetratingWall* createWall(QPointF qpf, QRectF qrf);
    Bot* createBot();
    void setUpViewRect();


public:
    GameBoard(QWidget* parentView);
    ~GameBoard() {}

    Player *player=nullptr;
    void removeCreature(MapEntity*);
    void actualizeSceneRect();

    friend class GameBoardBuilder;
    static GameBoardBuilder create(QWidget* pV);

public slots:
    void doStep();
};

#endif // GAMEBOARD_H
