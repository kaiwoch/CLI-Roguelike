#include "Mage.h"

Mage::Mage() : Entity() {
    MaxHPItem* RingOfLife = new MaxHPItem("ring of life", 150);
    HealItem* HealthPotion = new HealItem("health potion", 50);
    HealItem* Bread = new HealItem("bread", 10);
    DamageItem* HugeSword = new DamageItem("huge sword", 35);
    DamageItem* Stick = new DamageItem("stick", 25);
    
    std::vector<Item*> items = {RingOfLife, HealthPotion, Bread, HugeSword, Stick};
    int rand_size = rand() % items.size();
    for (unsigned int i = 0; i < rand_size; i++) {
        int rand_item = rand() % items.size();
        inventory.AddItem(items[rand_item]);
    }
    
    
    max_hp = 50;
    hp = max_hp;

    timer = 10;
    symbol = "M";
}

//Если передавать по значению, то игрок будет заспавнен в копии карты

void Mage::MoveLeft(Map& map) {
    Entity::MoveLeft(map);
    map.SetElement(pos, symbol);
}

void Mage::MoveRight(Map& map) {
    Entity::MoveRight(map);
    map.SetElement(pos, symbol);
}

void Mage::MoveUp(Map& map) {
    Entity::MoveUp(map);
    map.SetElement(pos, symbol);
}

void Mage::MoveDown(Map& map) {
    Entity::MoveDown(map);
    map.SetElement(pos, symbol);
}

void Mage::RandomAI(Map& map) {
    Entity::RandomAI(map);
    srand(time(NULL));
    int direction = rand() % 4;
    
    switch (direction) {
        case 0:
            MoveRight(map);
            break;
        case 1:
            MoveUp(map);
            break;
        case 2:
            MoveLeft(map);
            break;
        case 3:
            MoveDown(map);
            break;
    }
}

void Mage::Attack(Map& map) {
    Entity::Attack(map);
    
    if (timer >= 10) {
        timer = 0;
        
        float dir = map.GetDirectionToPlayer(this);
    
        int x = std::round(GetPosition().GetX() + walkSpeed * std::cos(dir));
        int y = std::round(GetPosition().GetY() - walkSpeed * std::sin(dir));
    
        Coordinates next_position;
        next_position.SetX(x);
        next_position.SetY(y);
        if (map.GetElement(next_position) == " ") {
            FireBall* fireball = new FireBall(map);
            map.SpawnObject(fireball, next_position);
        }
    }
}
