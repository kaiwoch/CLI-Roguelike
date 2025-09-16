#include "Interectable.h"
#include "Inventory.h"
#include "Item.h"
#pragma once

class Chest : public Interectable {
private:
    Inventory inventory;
public:
    Chest();
    void Open() override;
    void PrintInventory() override;
};
