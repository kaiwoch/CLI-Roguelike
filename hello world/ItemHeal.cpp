#include "ItemHeal.h"
#include "Player.h"

HealItem::HealItem(std::string name, int amount) : Item(name, "Heal") {
	this->amount = amount;
}

void HealItem::UseItem(Player& player) {
	player.Heal(amount);
}
