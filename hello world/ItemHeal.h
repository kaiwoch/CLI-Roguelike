#include "Item.h"
#include <string>
#pragma once

class HealItem : public Item {
public:
	HealItem(std::string name, int amount);
	void UseItem(Player& player) override;
};
