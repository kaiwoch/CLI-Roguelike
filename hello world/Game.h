#include "Map.h"
#include "CrossplatformFuncs.h"
#pragma once

class Game {
private:
    bool isRunning;
    bool isDebug;
    Map map;
    CrossplatformFuns cf;
public:
    Game();
    
    void Run();
    bool Stop();
    void PrintEntityHPBar(Entity& player);
};
