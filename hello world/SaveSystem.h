#include "Include/nlohmann/json.hpp"
#include "CrossplatformFuncs.h"
#include "Level.h"
#include <string>
#pragma once

class SaveSystem {
private:
    CrossplatformFuns cf;
public:
    void TestFunc(Level level);
    Level Load();
};
