#include "Map.h"
#include "Coordinates.h"
#include "Inventory.h"
#include "CrossplatformFuncs.h"
#include <string>
#include <time.h>
#include "Item.h"
#include "ItemMaxHP.h"
#include "ItemHeal.h"
#include "ItemDamage.h"
#include "Include/nlohmann/json.hpp"

using json = nlohmann::json;

#pragma once

enum State {
    Idle,
    Attack,
    Die
};

class Entity {
protected:
    std::string type;
    CrossplatformFuns cf;
    State state;
    int max_hp;
    int hp;
    int damage;
    Coordinates pos;
    int walkSpeed;
    std::string symbol;
    Inventory inventory;
    int timer;
public:
    Entity(std::string type);
    virtual void MoveLeft(Map& map);
    virtual void MoveRight(Map& map);
    virtual void MoveUp(Map& map);
    virtual void MoveDown(Map& map);
    virtual void PrintInventory();
    virtual void RandomAI(Map& map);
    virtual void Damage(Entity* entity, int damage);
    virtual void Attack(Map& map);
    virtual void TakeDamage(int damage);
    Coordinates GetPosition() const;
    int GetHP() const;
    Inventory GetInventory() const;
    int GetMaxHP() const;
    std::string GetSymbol();
    void SetPosition(Coordinates position);
    void Update(Map& map);
    void SetState(State state);

    //===========================================
    virtual std::string getType() const;
    friend void to_json(json& j, const Entity& e);
    friend void from_json(const json& j, Entity& e);
};

