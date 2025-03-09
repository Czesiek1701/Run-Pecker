#ifndef GAMEBOARDDIRECTOR_H
#define GAMEBOARDDIRECTOR_H

#include "gameboardbuilder.h"

// its not classical director
class GameBoardDirector
{
public:
    GameBoardDirector(QWidget*); // not used
    static GameBoard* buildForManualTest(QWidget*);
    static GameBoard* buildForPerformanceTest(QWidget*);
};

#endif // GAMEBOARDDIRECTOR_H
