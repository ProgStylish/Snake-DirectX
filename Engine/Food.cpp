#include "Food.h"
#include "Graphics.h"
#include "Colors.h"
#include <ctime>


Food::Food()
{
	reSpawn();
}

void Food::reSpawn() {
	srand(time(0));
	const int widthBase = Graphics::ScreenWidth / size;
	const int heightBase = Graphics::ScreenHeight / size;
	x = (rand() % widthBase) * size;
	y = (rand() % heightBase) * size;
}

void Food::draw(Graphics& gfx) const {
	gfx.putSquare(x, y, size, Colors::Cyan);
}

int Food::getX() const {
	return x;
}
int Food::getY() const {
	return y;
}
