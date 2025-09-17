#include "Inventory.h"

void Inventory::PrintInventory() {
    std::cout << "       INVENTORY   " << std::endl;
    std::cout << "-======================-" << std::endl;
    for (unsigned int i = 0; i < inventory.size(); i++) {
        std::cout << i + 1 << ". " <<  inventory[i]->GetName() << std::endl;
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

std::vector<Item*> Inventory::GetInventory() {
    return inventory;
}

Item* Inventory::ChoiseItem(unsigned int index) {
    if (inventory.size() < index - 1) {
        return nullptr;
    }

    return inventory[index - 1];
}

void Inventory::RemoveItem(Item *item) {
    for (unsigned int i = 0; i < inventory.size(); i++) {
        if (item->GetName() == inventory[i]->GetName()) {
            inventory.erase(inventory.cbegin() + i);
        }
    }
}
