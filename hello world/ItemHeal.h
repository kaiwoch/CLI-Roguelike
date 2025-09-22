#include "Item.h"
#include <string>
#pragma once

class HealItem : public Item {
private:
	int healAmount;
public:
	HealItem(std::string name, int healAmount);
	void UseItem(Player& player) override;
};