#include "Interectable.h"


Interectable::Interectable(){
    isDoor = false;
}

Coordinates Interectable::GetPosition() {
    return pos;
}

void Interectable::SetPosition(Coordinates position) {
    pos = position;
}

char Interectable::GetSymbol() {
    return symbol;
}

void Interectable::PrintInventory() {
    
}

void Interectable::Open(Inventory &object_inventory) {
    
}

bool Interectable::GetIsDoor() {
    return isDoor;
}
