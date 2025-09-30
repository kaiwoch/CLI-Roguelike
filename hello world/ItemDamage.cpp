#include "ItemDamage.h"
#include "Player.h"

DamageItem::DamageItem(std::string name, int amount) : Item(name, "Damage") {
	this->amount = amount;
}

void DamageItem::UseItem(Player& player) {
	player.SetDamage(amount);
}
