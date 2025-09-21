#include "Entity.h"

Entity::Entity() {
    walkSpeed = 1;
    max_hp = 100;
    hp = 100;
}

void Entity::MoveLeft(Map& map) {
    Coordinates leftPos;
    leftPos.SetX(pos.GetX() - walkSpeed);
    leftPos.SetY(pos.GetY());
    
    if (map.GetElement(leftPos) == ' ') {
        map.SetElement(pos, ' ');
        pos = leftPos;
    }
}

void Entity::MoveRight(Map& map) {
    Coordinates rightPos;
    rightPos.SetX(pos.GetX() + walkSpeed);
    rightPos.SetY(pos.GetY());
    
    if (map.GetElement(rightPos) == ' ') {
        map.SetElement(pos, ' ');
        pos = rightPos;
    }
}

void Entity::MoveUp(Map& map) {
    Coordinates upPos;
    upPos.SetX(pos.GetX());
    upPos.SetY(pos.GetY() - walkSpeed);
    
    if (map.GetElement(upPos) == ' ') {
        map.SetElement(pos, ' ');
        pos = upPos;
    }
}

void Entity::MoveDown(Map& map) {
    Coordinates downPos;
    downPos.SetX(pos.GetX());
    downPos.SetY(pos.GetY() + walkSpeed);
    
    if (map.GetElement(downPos) == ' ') {
        map.SetElement(pos, ' ');
        pos = downPos;
    }
}

void Entity::TakeDamage(int damage) {
    if (hp - damage < 0) {
        hp = 0;
    } else {
        hp -= damage;
    }
}

/*
bool Entity::EntityIsNear(Entity object) {
    if (-1 <= pos.GetX() - object.pos.GetX() and pos.GetX() - object.pos.GetX() <= 1) {
        if (-1 <= pos.GetY() - object.pos.GetY() and pos.GetY() - object.pos.GetY() <= 1) {
            return true;
        }
    }
    return false;
} */

void Entity::Attack(Entity* entity, int damage) {
    entity->TakeDamage(damage);
}

Coordinates Entity::GetPosition() {
    return pos;
}

void Entity::PrintInventory() {
    inventory.PrintInventory();
}

int Entity::GetHP() {
    return hp;
}

char Entity::GetSymbol() {
    return symbol;
}

void Entity::SetPosition(Coordinates position) {
    pos = position;
}

void Entity::RandomAI(Map& map) {

}

