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

void Map::SpawnObject(Interectable* object) {
    objects.push_back(object);
    srand(time(NULL));
    while(true){
        Coordinates tmpl_position;
        tmpl_position.SetX(rand() % Size().GetX());
        tmpl_position.SetY(rand() % Size().GetY());
        if(GetElement(tmpl_position) == ' ') {
            object->SetPosition(tmpl_position);
            SetElement(object->GetPosition(), object->GetSymbol());
            break;
        }
    }
}

Interectable* Map::GetNearstInterectableObject(Coordinates position) {
    for (unsigned int i = 0; i < objects.size(); i++) {
        if (-1 <= position.GetX() - objects[i]->GetPosition().GetX() and position.GetX() - objects[i]->GetPosition().GetX() <= 1) {
            if (-1 <= position.GetY() - objects[i]->GetPosition().GetY() and position.GetY() - objects[i]->GetPosition().GetY() <= 1) {
                return objects[i];
            }
        }
    }
    return nullptr;
}
