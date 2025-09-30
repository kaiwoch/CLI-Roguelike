#include "Interectable.h"


Interectable::Interectable(std::string type){
    this->type = type;
    isDoor = false;
}

Coordinates Interectable::GetPosition() const {
    return pos;
}

void Interectable::SetPosition(Coordinates position) {
    pos = position;
}

std::string Interectable::GetSymbol() {
    return symbol;
}

void Interectable::PrintInventory() {
    
}

void Interectable::Open(Inventory &object_inventory) {
    
}

bool Interectable::GetIsDoor() {
    return isDoor;
}

std::string Interectable::GetType() const {
    return type;
}

Inventory Interectable::GetInventory() const {
    return inventory;
}

void Interectable::SetType(std::string type) {
    this->type = type;
}
