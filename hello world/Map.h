#include <vector>
#include "Coordinates.h"
#include "Interectable.h"
#pragma once

class Map {
private:
    int width;
    int height;
    int fillPercent;
    std::vector<Interectable*> objects;
    std::vector<std::vector<char>> map;
public:
    Map();
    
    void PrintMap();
    Coordinates Size();
    char GetElement(Coordinates coordinates);
    void SetElement(Coordinates coordinates, char object);
    void SpawnObject(Interectable* object);
    void DeleteObject(Interectable* object);
    Interectable* GetNearstInterectableObject(Coordinates position);
    void GenerateMap();
    int GetNeighbourCount(unsigned int x, unsigned int y);
    void SmoothMap();
    void FillOuterWalls();
};
