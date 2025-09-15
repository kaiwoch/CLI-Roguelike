#include "Chest.h"
#include <iostream>

Chest::Chest(Map& map) : Interectable() {
    symbol = 'C';
    SpawnObject(map);
}

void Chest::SpawnObject(Map& map){
    Interectable::SpawnObject(map);
    map.SetElement(pos, symbol);
}

void Chest::Open() {
    
}
