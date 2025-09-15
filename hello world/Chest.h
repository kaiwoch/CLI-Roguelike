#include "Interectable.h"
#pragma once

class Chest : public Interectable {
public:
    Chest(Map& map);
    void SpawnObject(Map& map) override;
    void Open() override;
};
