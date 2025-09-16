#include "Player.h"

Player::Player(Map& map) : Entity() {
    symbol = 'P';
    SpawnEntity(map);
}

//Если передавать по значению, то игрок будет заспавнен в копии карты
void Player::SpawnEntity(Map& map){
    Entity::SpawnEntity(map);
    map.SetElement(pos, symbol);
}

void Player::MoveLeft(Map& map) {
    Entity::MoveLeft(map);
    map.SetElement(pos, symbol);
}

void Player::MoveRight(Map& map) {
    Entity::MoveRight(map);
    map.SetElement(pos, symbol);
}

void Player::MoveUp(Map& map) {
    Entity::MoveUp(map);
    map.SetElement(pos, symbol);
}

void Player::MoveDown(Map& map) {
    Entity::MoveDown(map);
    map.SetElement(pos, symbol);
}

void Player::Use(Map& map) {
    auto object = map.GetNearstInterectableObject(pos);
    if (object != nullptr) {
        object->PrintInventory();
    }
}

