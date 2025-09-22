#include "Chest.h"
#include <iostream>
#include <vector>

Chest::Chest() : Interectable() {
    MaxHPItem* RingOfLife = new MaxHPItem("ring of life", 150);
    HealItem* HealthPotion = new HealItem("health potion", 50);
    HealItem* Bread = new HealItem("bread", 10); 
    DamageItem* HugeSword = new DamageItem("huge sword", 35);
    DamageItem* Stick = new DamageItem("stick", 25);
    
    std::vector<Item*> items = {RingOfLife, HealthPotion, Bread, HugeSword, Stick};
    int rand_size = rand() % items.size();
    for (unsigned int i = 0; i < rand_size; i++) {
        int rand_item = rand() % items.size();
        inventory.AddItem(items[rand_item]);
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
