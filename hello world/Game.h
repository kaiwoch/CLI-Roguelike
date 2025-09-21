#include "Map.h"
#pragma once

class Game {
private:
    bool isRunning;
    bool isDebug;
    Map map;
public:
    Game();
    
    void Run();
    bool Stop();
};
