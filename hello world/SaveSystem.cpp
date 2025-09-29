#include "SaveSystem.h"
#include <iostream>
#include <fstream>
#include <filesystem>

using json = nlohmann::json;

void to_json(json& j, const Item& i) {
        j = json{{"name", i.GetName()},
                {"type", i.GetType()}
            };
    };
void from_json(const json& j, Item& i) {
        //j.at("type").get_to(t.setType());
}

void to_json(json& j, const Coordinates& c) {
        j = json{{"x", c.GetX()},
                {"y", c.GetY()}
            };
    };
void from_json(const json& j, Coordinates& c) {
        //j.at("type").get_to(t.setType());
}

void to_json(json& j, const Entity& e) {
        j = json{{"type", e.getType()},
                {"hp", e.GetHP()},
                {"max_hp", e.GetMaxHP()},
                {"pos", e.GetPosition()},
                {"inv", json::array()}
            };
        //TODO: Я особо не заморачивался, тут лютый костыль, срочно исправить
        std::vector<Item*> inventory = e.GetInventory().GetInventory();

        for (Item* item : inventory) {
            if (item) {
                json item_json = *item;
                j["inv"].push_back(item_json);
            }
        }
    };
void from_json(const json& j, Entity& e) {
        //j.at("type").get_to(t.setType());
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
    };
void from_json(const json& j, Interectable& i) {
        //j.at("type").get_to(t.setType());
}

void SaveSystem::TestFunc(Level level) {
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

void SaveSystem::Load() {
        std::fstream File;
        File.open(R"(save.json)", std::ios::in);

        json Document;
        File >> Document;

        File.close();

        //Level level = Document["level"].get<Level>();
}

