#include "Coordinates.h"

int Coordinates::GetX() const {
    return x;
}

int Coordinates::GetY() const {
    return y;
}

void Coordinates::SetX(unsigned int x) {
    this->x = x;
}

void Coordinates::SetY(unsigned int y) {
    this->y = y;
}
