#include "Interectable.h"
#pragma once

class Chest : public Interectable {
public:
    Chest();
    void Open() override;
};
