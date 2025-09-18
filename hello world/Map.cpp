#include "Map.h"
#include <iostream>

Map::Map() {
    GenerateMap();
    for (int i = 0; i < 6; i++) {
        SmoothMap();
        FillOuterWalls();
    }
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

void Map::DeleteObject(Interectable* object) {
    std::cout << objects.size() << std::endl;
    SetElement(object->GetPosition(), ' ');
    for (unsigned int i = 0; i < objects.size(); i++) {
        if (object == objects[i]) {
            objects.erase(objects.cbegin() + i);
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

void Map::GenerateMap() {
    srand(time(NULL));
    width = 20;
    height = 20;
    fillPercent = 30;

    std::vector<char> line;

    for (unsigned int y = 0; y < width; y++) {
        for (unsigned int x = 0; x < height; x++) {
            if (rand() % 100 < fillPercent) {
                line.push_back('#');
            } else {
                line.push_back(' ');
            }
        }
        map.push_back(line);
        line = {};
    }
}

int Map::GetNeighbourCount(unsigned int x, unsigned int y) {
    int count = 0;
    int low_x = 1;
    int low_y = 1;

    if (x == 0) {
        low_x = 0;
    }
    if (y == 0) {
        low_y = 0;
    }
        
    for (unsigned int dy = y - low_y; dy < y + 2; dy++) {
        if (dy == width) {
            break;
        }
        for (unsigned int dx = x - low_x; dx < x + 2; dx++) {
            if (dx == height) {
                break;
            }
            if (map[dy][dx] == '#') {
                count++;
            }
        }
    }
    return count;
}

void Map::SmoothMap() {
    for (unsigned int y = 0; y < width; y++) {
        for (unsigned int x = 0; x < height; x++) {
            int neighbourCount = GetNeighbourCount(x, y);
            if (neighbourCount > 3) {
                map[y][x] = ' ';
            } else {
                map[y][x] = '#';
            }
        }
        
    }
}

void Map::FillOuterWalls() {
    for (unsigned int y = 0; y < width; y++) {
        for (unsigned int x = 0; x < height; x++) {
            if (x == 0 || y == 0 || x == height - 1 || y == height - 1) {
                map[y][x] = '#';
            }
        }
    }
}
