#include "Chest.h"
#include <iostream>
#include <vector>

Chest::Chest() : Interectable() {
    Item item_001("apple");
    Item item_002("banana");
    Item item_003("water");
    Item item_004("melon");
    Item item_005("paper");
    
    std::vector<Item> items = {item_001, item_002, item_003, item_004, item_005};
    int rand_size = rand() % items.size();
    for (unsigned int i = 0; i < rand_size; i++) {
        inventory.AddItem(items[rand() % rand_size]);
    }

    symbol = 'C';
}


void Chest::Open() {
    
}

void Chest::PrintInventory() {
    Interectable::PrintInventory();
    inventory.PrintInventory();
}
