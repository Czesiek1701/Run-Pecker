#ifndef GAME_H
#define GAME_H
#include <QSharedData>

class Game : public QSharedData
{
public:
    Game();
    bool running;
};

#endif // GAME_H
