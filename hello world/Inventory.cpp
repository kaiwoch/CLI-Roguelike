#include "Inventory.h"

void Inventory::PrintInventory() {
    for (unsigned int i = 0; i < inventory.size(); i++) {
        std::cout << inventory[i]->GetName() << std::endl;
    }
}

void Inventory::AddItem(Item* item) {
    for (unsigned int i = 0; i < inventory.size(); i++) {
        if(item->GetName() == inventory[i]->GetName()){
                return;
            }
        }
    inventory.push_back(item);
}
