#include "Player.h"
#ifdef _WIN32
    #include <conio.h>
#else
    #include <ncurses.h>
#endif

Player::Player() : Entity() {
    symbol = "P";
    damage = 20;
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
        object->TakeDamage(damage);
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
    if (index <= inventory.GetInventory().size()) {
        auto item = inventory.ChoiseItem(index);
        if (item != nullptr) {
            item->UseItem(*this);
            inventory.RemoveItem(item);
        }
    } else {
        //printw("Item not found.\n");
        //std::cout << "Item not found." << std::endl;
    }
}

void Player::TakeDamage(int damage) {
    Entity::TakeDamage(damage);
}

void Player::SetMaxHP(int amount) {
    max_hp = amount;
}

void Player::SetDamage(int amount) {
    damage = amount;
}

