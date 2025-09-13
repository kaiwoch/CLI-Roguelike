#include <vector>
#include "Coordinates.h"
#pragma once

class Map {
private:
    std::vector<std::vector<char>> map;
public:
    Map();
    
    void PrintMap();
    Coordinates Size();
    char GetElement(Coordinates coordinates);
    void SetElement(Coordinates coordinates, char object);
};
