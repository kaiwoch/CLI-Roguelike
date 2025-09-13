#include "Map.h"
#include <iostream>

Map::Map() {
    map = {{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};
}

Coordinates Map::Size() {
    Coordinates SizeCoord;
    SizeCoord.SetX(map[0].size());
    SizeCoord.SetY(map.size());
    return SizeCoord;
}

void Map::SetElement(Coordinates coordinates, char object) {
    map[coordinates.GetY()][coordinates.GetX()] = object;
}

char Map::GetElement(Coordinates coordinates) {
    return map[coordinates.GetY()][coordinates.GetX()];
}

void Map::PrintMap() {
    for (unsigned int y = 0; y < Size().GetY(); y++) {
        for (unsigned int x = 0; x < Size().GetX(); x++) {
            std::cout << map[y][x] << " ";
        }
        std::cout << std::endl;
    }
}
