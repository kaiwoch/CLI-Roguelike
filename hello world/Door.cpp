#include "Door.h"

Door::Door() : Interectable("Door") {
    symbol = "D";
}

void Door::Open(Inventory& inventory) {
    isDoor = true;
}
