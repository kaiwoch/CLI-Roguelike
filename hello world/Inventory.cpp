#include "Inventory.h"
#ifdef _WIN32
    #include <conio.h>
    #include <cstdarg>
#else
    #include <ncurses.h>
#endif

void Inventory::PrintInventory() {
    //clear();
    cf.Print("\n       INVENTORY   \n");
    cf.Print("-======================-\n");
    
    for (unsigned int i = 0; i < inventory.size(); i++) {
        cf.Print("%d. %s\n", i + 1, inventory[i]->GetName().c_str());
    }
    #ifdef _WIN32
    
    #else
        refresh();
    #endif
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