#include "Map.h"
#pragma once

class Game {
private:
    bool isRunning;
    Map map;
public:
    Game();
    
    void Run();
    bool Stop();
};
