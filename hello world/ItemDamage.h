#include "Item.h"
#include <string>
#pragma once

class DamageItem : public Item {
private:
	int damageAmount;
public:
	DamageItem(std::string name, int damageAmount);
	void UseItem(Player& player) override;
};