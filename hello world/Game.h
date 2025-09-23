#include "Map.h"
#pragma once

class Game {
private:
    bool isRunning;
    bool isDebug;
    Map map;
    int GetInput();
    void Print(const char *fmt, ...);
public:
    Game();
    
    void Run();
    bool Stop();
};
