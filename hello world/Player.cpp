#include "Player.h"

Player::Player() : Entity() {
    max_hp = 100;
    hp = 50;
    symbol = 'P';
}

//Если передавать по значению, то игрок будет заспавнен в копии карты

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

bool Player::Use(Map& map) {
    auto object = map.GetNearstInterectableObject(pos);
    if (object != nullptr) {
        object->Open(inventory);
        map.DeleteObject(object);
        return object->GetIsDoor();
    }
    return false;
}

void Player::Attack(Map& map) {
    auto object = map.GetNearstEntityObject(pos);
    if (object != nullptr) {
        std::cout << object->GetSymbol() << std::endl;
    }
}

void Player::Heal(int healAmount) {
    if (hp + healAmount > max_hp) {
        hp = max_hp;
    } else {
        hp += healAmount;
    }
}

void Player::UseItem(unsigned int index) {
    auto item = inventory.ChoiseItem(index);
    if (item != nullptr) {
        item->UseItem(*this);
        inventory.RemoveItem(item);
    }
}

