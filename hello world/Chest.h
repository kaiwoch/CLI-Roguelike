#include "Interectable.h"
#include "Inventory.h"
#include "Item.h"
#include "ItemMaxHP.h"
#include "ItemHeal.h"
#include "ItemDamage.h"
#pragma once

class Chest : public Interectable {
private:
    Inventory inventory;
public:
    Chest();
    void Open(Inventory& inventory) override;
    void PrintInventory() override;
};
