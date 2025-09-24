#include "Map.h"
#include <iostream>
#include <cstdarg>

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#else
    #include <ncurses.h>
#endif
#include "Entity.h"

//Конструктор
Map::Map() {
    GenerateMap();
    for (int i = 0; i < 4; i++) {
        SmoothMap();
        FillOuterWalls();
    }
}

//Получить размер карты
Coordinates Map::Size() {
    Coordinates SizeCoord;
    SizeCoord.SetX(map[0].size());
    SizeCoord.SetY(map.size());
    return SizeCoord;
}

//Установить символьное представление объекта на карте
void Map::SetElement(Coordinates coordinates, std::string object) {
    map[coordinates.GetY()][coordinates.GetX()] = object;
}

//Получить символьное представление объекта на карте
std::string Map::GetElement(Coordinates coordinates) {
    return map[coordinates.GetY()][coordinates.GetX()];
}

//Отрисовка карты и запуск методов у объектов, находящихся на карте каждый кадр.
void Map::PrintMap() {
    //clear();
    #ifdef _WIN32

    #else
        static bool colors_initialized = false;
        if (!colors_initialized) {
            if (has_colors()) {
                start_color();
                init_pair(1, COLOR_WHITE, COLOR_BLACK);
                init_pair(2, COLOR_RED, COLOR_RED);
                init_pair(3, COLOR_GREEN, COLOR_BLACK);
                init_pair(4, COLOR_CYAN, COLOR_BLACK);
                init_pair(5, COLOR_YELLOW, COLOR_BLACK);
            }
            colors_initialized = true;
        }
    #endif
    for (unsigned int y = 0; y < Size().GetY(); y++) {
        for (unsigned int x = 0; x < Size().GetX(); x++) {
            std::string s = map[y][x];
            cf.SetColor(s);
        }
        cf.Print("\n");
    }


    for (unsigned int i = 0; i < entities.size(); i++) {
        entities[i]->RandomAI(*this);
    }


    for (unsigned int i = 0; i < entities.size(); i++) {
        if (entities[i]->GetSymbol() != "P") 
            entities[i]->Attack(*this);
    }
    //refresh();====
}

//Рандомный спавн Interectable
void Map::SpawnObject(Interectable* object) {
    objects.push_back(object);
    srand(time(NULL));
    while(true){
        Coordinates tmpl_position;
        tmpl_position.SetX(rand() % Size().GetX());
        tmpl_position.SetY(rand() % Size().GetY());
        if(GetElement(tmpl_position) == " ") {
            object->SetPosition(tmpl_position);
            SetElement(object->GetPosition(), object->GetSymbol());
            break;
        }
    }
}

//Перегрузка рандомный спавн Entity
void Map::SpawnObject(Entity* object) {
    entities.push_back(object);
    srand(time(NULL));
    while(true){
        Coordinates tmpl_position;
        tmpl_position.SetX(rand() % Size().GetX());
        tmpl_position.SetY(rand() % Size().GetY());
        if(GetElement(tmpl_position) == " ") {
            object->SetPosition(tmpl_position);
            SetElement(object->GetPosition(), object->GetSymbol());
            break;
        }
    }
}

//Перегрузка, спавн по координатам Entity
void Map::SpawnObject(Entity* object, Coordinates position) {
    entities.push_back(object);
    if(GetElement(position) == " ") {
        object->SetPosition(position);
        SetElement(object->GetPosition(), object->GetSymbol());
    }
}

//Удалить объект с карты Interectable
void Map::DeleteObject(Interectable* object) {
    //std::cout << entities.size() << std::endl;
    SetElement(object->GetPosition(), " ");
    for (unsigned int i = 0; i < objects.size(); i++) {
        if (object == objects[i]) {
            objects.erase(objects.cbegin() + i);
        }
    }
}

//Удалить объект с карты Entity
void Map::DeleteObject(Entity* object) {
    //std::cout << entities.size() << std::endl;
    SetElement(object->GetPosition(), " ");
    for (unsigned int i = 0; i < entities.size(); i++) {
        if (object == entities[i]) {
            entities.erase(entities.cbegin() + i);
        }
    }
}

//Получить ближайший объект Interectable
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

//Получить ближайший объект Entity
Entity* Map::GetNearstEntityObject(Coordinates position) {
    
    for (unsigned int i = 0; i < entities.size(); i++) {
        if (entities[i]->GetSymbol() != "P") {
            float dist = GetDistanceToPlayer(entities[i]);
            if (dist < 2.f) {
                return entities[i];
            }
        }
    }
    return nullptr;
}

//Получить объект Entity по координатам
Entity* Map::GetObjectA(Coordinates position) { //???????????????????????????????????????????????????????
    for (unsigned int i = 0; i < entities.size(); i++) {
        if (position.GetX() == entities[i]->GetPosition().GetX() && position.GetY() == entities[i]->GetPosition().GetY()) {
            return entities[i];
        }
    }
    return nullptr;
}

//Алгоритм процедурной генерации "Клеточные автоматы"
void Map::GenerateMap() {
    srand(time(NULL));
    width = 40;
    height = 40;
    fillPercent = 27;

    std::vector<std::string> line;

    for (unsigned int y = 0; y < width; y++) {
        for (unsigned int x = 0; x < height; x++) {
            if (rand() % 100 < fillPercent) {
                line.push_back("#");
            } else {
                line.push_back(" ");
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
            if (map[dy][dx] == "#") {
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
                map[y][x] = "#";
            } else {
                map[y][x] = " ";
            }
        }
        
    }
}

void Map::FillOuterWalls() {
    for (unsigned int y = 0; y < width; y++) {
        for (unsigned int x = 0; x < height; x++) {
            if (x == 0 || y == 0 || x == height - 1 || y == height - 1) {
                map[y][x] = "#";
            }
        }
    }
}

//Получить позицию игрока на карте
Coordinates Map::GetPlayerPosition() {
    for (unsigned int i = 0; i < entities.size(); i++) {
        if (entities[i]->GetSymbol() == "P") {
            return entities[i]->GetPosition();
        }
    }
    return Coordinates();
}

//Длина вектора от объекта до игрока
float Map::GetDistanceToPlayer(Entity* entity) {
    Coordinates player_pos = GetPlayerPosition();
    Coordinates entity_pos = entity->GetPosition();
    
    //Длина вектора
    float dist = std::sqrt(std::pow(entity_pos.GetX() - player_pos.GetX(), 2) + std::pow(entity_pos.GetY() - player_pos.GetY(), 2));
    return dist;
}

//Направление от объекта к игроку
float Map::GetDirectionToPlayer(Entity* entity) {
    Coordinates player_pos = GetPlayerPosition();
    Coordinates entity_pos = entity->GetPosition();
    
    float alpha = std::atan2(-(player_pos.GetY() - entity_pos.GetY()), player_pos.GetX() - entity_pos.GetX());
    
    //float angles = (alpha * (180.f / 3.14f));
    
    
    return alpha;
}

// Вывод основной информации в консоль
void Map::Debug() {
    cf.Print("%s\n", "Entities:");
    for (unsigned int i = 0; i < entities.size(); i++) {
        cf.Print("Char: %s PosX: %d PosY: %d DistToPlayer: %f DirToPlayer: %f HP: %d/%d\n", entities[i]->GetSymbol().c_str(), entities[i]->GetPosition().GetX(), entities[i]->GetPosition().GetY(), GetDistanceToPlayer(entities[i]), GetDirectionToPlayer(entities[i]), entities[i]->GetHP(), entities[i]->GetMaxHP());
    }
    cf.Print("%s\n", "Interectable:");
    for (unsigned int i = 0; i < objects.size(); i++) {
        cf.Print("Char: %s PosX: %d PosY: %d\n", objects[i]->GetSymbol().c_str(), objects[i]->GetPosition().GetX(), objects[i]->GetPosition().GetY());
    }
}

//Отрисовка луча от объекта к игроку
void Map::PrintLine(Entity* entity) {
    float dir = GetDirectionToPlayer(entity);
    int dist = GetDistanceToPlayer(entity) - 1;
    for (int i = 1; i <= dist; i++){
        int x = std::round(entity->GetPosition().GetX() + i * std::cos(dir));
        int y = std::round(entity->GetPosition().GetY() - i * std::sin(dir));
        
        Coordinates line_pos;
        line_pos.SetX(x);
        line_pos.SetY(y);
            
        SetElement(line_pos, ".");
    }
        
}
