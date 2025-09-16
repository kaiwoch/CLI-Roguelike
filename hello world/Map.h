#include <vector>
#include "Coordinates.h"
#include "Interectable.h"
#pragma once

class Map {
private:
    std::vector<Interectable*> objects;
    std::vector<std::vector<char>> map;
public:
    Map();
    
    void PrintMap();
    Coordinates Size();
    char GetElement(Coordinates coordinates);
    void SetElement(Coordinates coordinates, char object);
    void SpawnObject(Interectable* object);
    Interectable* GetNearstInterectableObject(Coordinates position);
};
