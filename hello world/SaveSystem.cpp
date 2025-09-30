#include "SaveSystem.h"
#include <iostream>
#include <fstream>
#include <filesystem>

using json = nlohmann::json;

void to_json(json& j, const Item& i) {
        j = json{{"name", i.GetName()},
                {"type", i.GetType()},
                {"amount", i.GetAmount()}
            };
    }


void to_json(json& j, const Coordinates& c) {
        j = json{{"x", c.GetX()},
                {"y", c.GetY()}
            };
    };
void from_json(const json& j, Coordinates& c) {
        c.SetX(j.at("x").get<int>());
        c.SetY(j.at("y").get<int>());
}

void to_json(json& j, const Entity& e) {
        j = json{{"type", e.getType()},
                {"hp", e.GetHP()},
                {"max_hp", e.GetMaxHP()},
                {"pos", e.GetPosition()},
                {"dmg", e.GetDamage()},
                {"inv", json::array()}
            };
        //TODO: Я особо не заморачивался, тут лютый костыль, срочно исправить
        std::vector<Item*> inventory = e.GetInventory()->GetInventory();

        for (Item* item : inventory) {
            if (item) {
                json item_json = *item;
                j["inv"].push_back(item_json);
            }
        }
    }

Item* CreateItemFromJson(const json& j) {
    std::string type = j.at("type").get<std::string>();
    std::string name = j.at("name").get<std::string>();
    int amount = j.at("amount").get<int>();

    Item* item = nullptr;

    if (type == "Heal") {
        item = new HealItem(name, amount);
    } else if (type == "MaxHP") {
        item = new MaxHPItem(name, amount);
    } else if (type == "Damage") {
        item = new DamageItem(name, amount);
    } else {
        std::cerr << "Unknown item type: " << type << std::endl;
        return nullptr;
    }
    
    return item;
}

Entity* CreateEntityFromJson(const json& j) {
    std::string type = j.at("type").get<std::string>();

    Entity* entity = nullptr;

    if (type == "Player") {
        entity = new Player();
    } else if (type == "Warrior") {
        entity = new Warrior();
    } else if (type == "Mage") {
        entity = new Mage();
    } else {
        std::cerr << "Unknown entity type: " << type << std::endl;
        return nullptr;
    }

    from_json(j, *entity);
    return entity;
}

Interectable* CreateInterectableFromJson(const json& j) {
    std::string type = j.at("type").get<std::string>();

    Interectable* inter = nullptr;

    if (type == "Chest") {
        inter = new Chest();
    } else if (type == "Door") {
        inter = new Door();
    } else {
        std::cerr << "Unknown interactable type: " << type << std::endl;
        return nullptr;
    }

    from_json(j, *inter);
    return inter;
}

void from_json(const json& j, Entity& e) {
        e.SetType(j.at("type").get<std::string>());
        e.SetHP(j.at("hp").get<int>());
        e.SetMaxHP(j.at("max_hp").get<int>());
        e.SetDamage(j.at("dmg").get<int>());

        Coordinates pos = j.at("pos").get<Coordinates>();
        e.SetPosition(pos);

        if (j.contains("inv")) {
            for (const auto& item_json : j["inv"]) {
                Item* item = CreateItemFromJson(item_json);
                e.GetInventory()->AddItem(item);
            }
        }
}

void to_json(json& j, const Interectable& i) {
    j = json{{"type", i.GetType()},
            {"pos", i.GetPosition()},
            {"inv", json::array()}
        };
    //TODO: Я особо не заморачивался, тут лютый костыль, срочно исправить
    if (i.GetType() == "Chest") {
            std::vector<Item*> inventory = i.GetInventory().GetInventory();

            for (Item* item : inventory) {
                if (item) {
                    json item_json = *item;
                    j["inv"].push_back(item_json);
                }
            }
    }
}

void from_json(const json& j, Interectable& i) {
    i.SetType(j.at("type").get<std::string>()); 
    i.SetPosition(j.at("pos").get<Coordinates>());

    if (i.GetType() == "Chest" && j.contains("inv")) {
        for (const auto& item_json : j["inv"]) {
            Item* item = CreateItemFromJson(item_json);
            if (item) {
                i.GetInventory().AddItem(item);
            }
        }
    }
}


void from_json(const json& j, Map& m) {
    // Загрузка текстовой карты
    std::vector<std::vector<std::string>> text_map = j.at("text_map").get<std::vector<std::vector<std::string>>>();
    m.SetMap(text_map);

    // Загрузка сущностей (Entity*)
    if (j.contains("entities")) {
        for (const auto& entity_json : j["entities"]) {
            Entity* entity = CreateEntityFromJson(entity_json);  // Используем фабрику
            if (entity) {
                m.AddEntity(entity);
            }
        }
    }

    // Загрузка интерактивных объектов (Interectable*)
    if (j.contains("interectables")) {
        for (const auto& inter_json : j["interectables"]) {
            Interectable* inter = CreateInterectableFromJson(inter_json);  // Тоже фабрика
            if (inter) {
                m.AddInterectable(inter);
            }
        }
    }
}

void from_json(const json& j, Level& level) {
    level.SetStageNumber(j.at("stage_level").get<int>());
    
    Map map = j.at("map").get<Map>();
    level.SetMap(map);
}


void SaveSystem::Save(Level level) {
    //cf.Print("Current dir: %s", std::filesystem::current_path().c_str());
    json Document;
    Document["stage_level"] = level.GetStageNumber();
    
    Map map = level.GetCurrentMap();
    Document["map"]["text_map"] = map.GetMap();

    std::vector<Entity*> entities = map.GetEntity();
    Document["map"]["entities"] = json::array();

    for (Entity* entity : entities) {
        if (entity) {
            json entityJson = *entity;
            Document["map"]["entities"].push_back(entityJson);
        } else {

        }
    }
    std::vector<Interectable*> interectables = map.GetInterectable();
    for (Interectable* interectable : interectables) {
        if (interectable) {
            json interectable_json = *interectable;
            Document["map"]["interectables"].push_back(interectable_json);
        } else {

        }
    }
    
    std::fstream File;
    File.open(R"(save.json)", std::ios::out);
    
    File << Document;
    File.close();
}

Level SaveSystem::Load() {
    std::fstream File;
    File.open(R"(save.json)", std::ios::in);

    json Document;
    File >> Document;

    File.close();

    Level level = Document.get<Level>();
    return level;
}

