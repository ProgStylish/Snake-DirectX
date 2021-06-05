#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include <Vector>
class Snake {
private:
	struct Link {
		int x = Graphics::ScreenWidth / 2;
		int y = Graphics::ScreenHeight / 2;
	};
	int linkSize = 10;
	int length = 5;
	std::vector<Link> body;
	boolean movingUp = false;
	boolean movingDown = false;
	boolean movingRight = false;
	boolean movingLeft = true;
	void autoCut();
public:
	Snake();
	void draw(Graphics& gfx) const;
	void grow();
	void move();
	void changeDirection(Keyboard& kbd);
	int getHeadX() const;
	int getHeadY() const;
};
