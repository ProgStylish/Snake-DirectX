#pragma once
#include "Colors.h"
#include "Graphics.h"
class Board {
public:
	Board(int width, int height);
	void draw(Graphics& gfx);
private:
	int width;
	int height;
};