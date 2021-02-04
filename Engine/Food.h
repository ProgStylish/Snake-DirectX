#pragma once
#include "Colors.h"
#include "Graphics.h"
class Food {
public:
	Food();
	void draw(Graphics& gfx) const;
	void reSpawn();
	int getX() const;
	int getY() const;
private:
	int x;
	int y;
	int size = 10;

};