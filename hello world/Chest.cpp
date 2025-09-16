#include "Chest.h"
#include <iostream>

Chest::Chest() : Interectable() {
    Item item_001("apple");
    Item item_002("banana");
    inventory.AddItem(item_001);
    inventory.AddItem(item_002);
    symbol = 'C';
}


void Chest::Open() {
    
}

void Chest::PrintInventory() {
    Interectable::PrintInventory();
    inventory.PrintInventory();
}
