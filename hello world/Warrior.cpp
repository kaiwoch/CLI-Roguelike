#include "Warrior.h"

Warrior::Warrior(Map& map) : Entity() {
    symbol = 'W';
    SpawnEntity(map);
}

//Если передавать по значению, то игрок будет заспавнен в копии карты
void Warrior::SpawnEntity(Map& map){
    Entity::SpawnEntity(map);
    map.SetElement(pos, symbol);
}

void Warrior::MoveLeft(Map& map) {
    Entity::MoveLeft(map);
    map.SetElement(pos, symbol);
}

void Warrior::MoveRight(Map& map) {
    Entity::MoveRight(map);
    map.SetElement(pos, symbol);
}

void Warrior::MoveUp(Map& map) {
    Entity::MoveUp(map);
    map.SetElement(pos, symbol);
}

void Warrior::MoveDown(Map& map) {
    Entity::MoveDown(map);
    map.SetElement(pos, symbol);
}

void Warrior::RandomeAI(Map& map) {
    srand(time(NULL));
    int direction = rand() % 4;
    
    switch (direction) {
        case 0:
            MoveRight(map);
            break;
        case 1:
            MoveUp(map);
            break;
        case 2:
            MoveLeft(map);
            break;
        case 3:
            MoveDown(map);
            break;
    }
}


