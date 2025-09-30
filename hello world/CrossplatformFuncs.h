#include <string>
#pragma once

enum WindowsColors {
    Green = 2,
    Blue,
    Red,
    Yellow = 6,
    White
};

class CrossplatformFuns {
public:
	void Print(const char *fmt, ...);
	int GetInput();
	void SetColor(std::string s);
    void ClearScreen();
};
