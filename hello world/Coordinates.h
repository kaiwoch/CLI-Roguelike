#include "Include/nlohmann/json.hpp"
#pragma once

using json = nlohmann::json;

class Coordinates {
private:
    unsigned int x;
    unsigned int y;
public:
    int GetX() const;
    int GetY() const;
    
    void SetX(unsigned int x);
    void SetY(unsigned int y);

    friend void to_json(json& j, const Coordinates& c);
    friend void from_json(const json& j, Coordinates& c);
};

