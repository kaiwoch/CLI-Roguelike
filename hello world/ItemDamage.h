#include "Item.h"
#include <string>
#pragma once

class DamageItem : public Item {
public:
	DamageItem(std::string name, int amount);
	void UseItem(Player& player) override;
};
