#pragma once

class Coordinates {
private:
    unsigned int x;
    unsigned int y;
public:
    int GetX();
    int GetY();
    
    void SetX(unsigned int x);
    void SetY(unsigned int y);
};

