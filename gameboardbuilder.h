#ifndef GAMEBOARDBUILDER_H
#define GAMEBOARDBUILDER_H

#include "gameboard.h"

class GameBoardBuilder
{
    GameBoard* productGB;
public:
    GameBoardBuilder(QWidget*);
    GameBoard* build();

    GameBoardBuilder& setPlayer();
    GameBoardBuilder& addBot();
    GameBoardBuilder& addBot(int);
    GameBoardBuilder& addWall();
    GameBoardBuilder& addWall(QPointF);

    operator GameBoard*()
    {return std::move(build());} // for casting

};


#endif // GAMEBOARDBUILDER_H
