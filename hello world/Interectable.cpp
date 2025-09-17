#include "Interectable.h"


Interectable::Interectable(){
    
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

void Interectable::SetIsOpened(bool isOpened) {
    this->isOpened = isOpened;
}

bool Interectable::GetIsOpened() {
    return isOpened;
}
