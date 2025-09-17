#include "Chest.h"
#include <iostream>
#include <vector>

Chest::Chest() : Interectable() {
    Ring* RingOfLife = new Ring("ring of life", 50);
    inventory.AddItem(RingOfLife);
    std::vector<Item*> items = {RingOfLife};
    int rand_size = rand() % items.size();
    for (unsigned int i = 0; i < rand_size; i++) {
        inventory.AddItem(items[rand() % rand_size]);
    }

    symbol = 'C';
}


void Chest::Open(Inventory& object_inventory) {
    for (unsigned int i = 0; i < inventory.GetInventory().size(); i++) {
        object_inventory.AddItem(inventory.GetInventory()[i]);
    }
}

void Chest::PrintInventory() {
    Interectable::PrintInventory();
    inventory.PrintInventory();
}
