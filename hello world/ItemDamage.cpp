#include "ItemDamage.h"
#include "Player.h"

DamageItem::DamageItem(std::string name, int damageAmount) : Item(name, "Damage") {
	this->damageAmount = damageAmount;
}

void DamageItem::UseItem(Player& player) {
	player.SetDamage(damageAmount);
}