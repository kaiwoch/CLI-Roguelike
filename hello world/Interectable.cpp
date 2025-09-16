#include "Interectable.h"


Interectable::Interectable(){
    
}

void Interectable::Open(){
    std::cout << "Open!" << std::endl;
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
