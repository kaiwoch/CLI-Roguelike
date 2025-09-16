#include "Entity.h"

Entity::Entity() {
    walkSpeed = 1;
}

void Entity::SpawnEntity(Map& map){
    srand(time(NULL));
    while(true){
        Coordinates tmpl_position;
        tmpl_position.SetX(rand() % map.Size().GetX());
        tmpl_position.SetY(rand() % map.Size().GetY());
        if(map.GetElement(tmpl_position) == ' ') {
            pos = tmpl_position;
            break;
        }
    }
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

/*
bool Entity::EntityIsNear(Entity object) {
    if (-1 <= pos.GetX() - object.pos.GetX() and pos.GetX() - object.pos.GetX() <= 1) {
        if (-1 <= pos.GetY() - object.pos.GetY() and pos.GetY() - object.pos.GetY() <= 1) {
            return true;
        }
    }
    return false;
} */

Coordinates Entity::GetPosition() {
    return pos;
}

