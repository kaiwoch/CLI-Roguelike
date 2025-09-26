#include "Entity.h"

Entity::Entity() {
    state = State::Idle;
    walkSpeed = 1;
    
    max_hp = 100;
    hp = max_hp;
}

void Entity::MoveLeft(Map& map) {
    Coordinates leftPos;
    leftPos.SetX(pos.GetX() - walkSpeed);
    leftPos.SetY(pos.GetY());
    
    if (map.GetElement(leftPos) == " ") {
        map.SetElement(pos, " ");
        pos = leftPos;
    }
}

void Entity::MoveRight(Map& map) {
    Coordinates rightPos;
    rightPos.SetX(pos.GetX() + walkSpeed);
    rightPos.SetY(pos.GetY());
    
    if (map.GetElement(rightPos) == " ") {
        map.SetElement(pos, " ");
        pos = rightPos;
    }
}

void Entity::MoveUp(Map& map) {
    Coordinates upPos;
    upPos.SetX(pos.GetX());
    upPos.SetY(pos.GetY() - walkSpeed);
    
    if (map.GetElement(upPos) == " ") {
        map.SetElement(pos, " ");
        pos = upPos;
    }
}

void Entity::MoveDown(Map& map) {
    Coordinates downPos;
    downPos.SetX(pos.GetX());
    downPos.SetY(pos.GetY() + walkSpeed);
    
    if (map.GetElement(downPos) == " ") {
        map.SetElement(pos, " ");
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

void Entity::Damage(Entity* entity, int damage) {
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

std::string Entity::GetSymbol() {
    return symbol;
}

void Entity::SetPosition(Coordinates position) {
    pos = position;
}

void Entity::RandomAI(Map& map) {

}

void Entity::Attack(Map& map) {

}

int Entity::GetMaxHP() {
    return max_hp;
}

void Entity::Update(Map& map) {
    float dist = map.GetDistanceToPlayer(this);

    if (dist < 7 && symbol != "*") SetState(State::Attack);
    else SetState(State::Idle);

    if (hp <= 0) SetState(State::Die);

    switch (state) {
    case State::Idle:
        if (symbol != "P") {
            RandomAI(map);
        }
        break;
    case State::Attack:
        if (symbol != "P") {
            Attack(map);
        }
        break;

    case State::Die:
        map.DeleteObject(this);
        break;

    default:
        if (symbol != "P") {
            RandomAI(map);
        }
        break;
    }
}

void Entity::SetState(State state) {
    this->state = state;
}

