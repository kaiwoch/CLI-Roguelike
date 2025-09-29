#include "ItemHeal.h"
#include "Player.h"

HealItem::HealItem(std::string name, int healAmount) : Item(name, "Heal") {
	this->healAmount = healAmount;
}

void HealItem::UseItem(Player& player) {
	player.Heal(healAmount);
}