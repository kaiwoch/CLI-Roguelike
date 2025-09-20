#include "Door.h"

Door::Door() {
    symbol = 'D';
}

void Door::Open(Inventory& inventory) {
    isDoor = true;
}
