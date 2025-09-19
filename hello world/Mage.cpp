#include "Mage.h"

Mage::Mage() : Entity() {
    symbol = 'M';
}

//Если передавать по значению, то игрок будет заспавнен в копии карты

void Mage::MoveLeft(Map& map) {
    Entity::MoveLeft(map);
    map.SetElement(pos, symbol);
}

void Mage::MoveRight(Map& map) {
    Entity::MoveRight(map);
    map.SetElement(pos, symbol);
}

void Mage::MoveUp(Map& map) {
    Entity::MoveUp(map);
    map.SetElement(pos, symbol);
}

void Mage::MoveDown(Map& map) {
    Entity::MoveDown(map);
    map.SetElement(pos, symbol);
}

void Mage::RandomeAI(Map& map) {
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

