#include "Snake.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Colors.h"

Snake::Snake()
{
	for (int i = 0; i < length; i++) {
		body.push_back(Link());
	}
	for (int i = 1; i < length; i++) {
		body[i].x = body[i - 1].x + linkSize;
	}
}

void Snake::draw(Graphics& gfx) const
{
	for (int i = 0; i < length; i++) {
		if (i == 0) {
			gfx.putSquare(body[i].x, body[i].y, linkSize, Colors::Yellow);
		}
		else if(i % 3 == 0){ 
			gfx.putSquare(body[i].x, body[i].y, linkSize, Color(0,255,0));
		}
		else if(i % 2 == 0){
			gfx.putSquare(body[i].x, body[i].y, linkSize, Color(20, 200, 20));
		}
		else {
			gfx.putSquare(body[i].x, body[i].y, linkSize, Color(20, 150, 20));
		}
	}
}

void Snake::grow()
{
	length++;
}
void Snake::move()
{
	for (int i = length-1; i > 0; i--) {
		body[i].x = body[i - 1].x;
		body[i].y = body[i - 1].y;
	}

	if (movingUp) {
		body[0].y -= linkSize;
		if (body[0].y < 0) {
			body[0].y = Graphics::ScreenHeight - linkSize;
		}
	}
	if (movingDown) {
		body[0].y += linkSize;
		if (body[0].y > Graphics::ScreenHeight - linkSize) {
			body[0].y = 0;
		}
	}
	if (movingRight) {
		body[0].x += linkSize;
		if (body[0].x > Graphics::ScreenWidth - linkSize) {
			body[0].x = 0;
		}
	}
	if (movingLeft) {
		body[0].x -= linkSize;
		if (body[0].x < 0) {
			body[0].x = Graphics::ScreenWidth - linkSize;
		}
	}
}

void Snake::changeDirection(Keyboard& kbd)
{
	if (kbd.KeyIsPressed(VK_UP) && !movingDown &&
		!kbd.KeyIsPressed(VK_RIGHT) &&
		!kbd.KeyIsPressed(VK_LEFT) &&
		!kbd.KeyIsPressed(VK_DOWN)) {
		movingUp = true;
		movingDown = false;
		movingRight = false;
		movingLeft = false;
	}
	if (kbd.KeyIsPressed(VK_DOWN) && !movingUp &&
		!kbd.KeyIsPressed(VK_RIGHT) &&
		!kbd.KeyIsPressed(VK_UP) &&
		!kbd.KeyIsPressed(VK_LEFT)) {
		movingUp = false;
		movingDown = true;
		movingRight = false;
		movingLeft = false;
	}
	if (kbd.KeyIsPressed(VK_RIGHT) && !movingLeft &&
		!kbd.KeyIsPressed(VK_LEFT) &&
		!kbd.KeyIsPressed(VK_UP) &&
		!kbd.KeyIsPressed(VK_DOWN)) {
		movingUp = false;
		movingDown = false;
		movingRight = true;
		movingLeft = false;
	}
	if (kbd.KeyIsPressed(VK_LEFT) && !movingRight &&
		!kbd.KeyIsPressed(VK_RIGHT) &&
		!kbd.KeyIsPressed(VK_UP) &&
		!kbd.KeyIsPressed(VK_DOWN)) {
		movingUp = false;
		movingDown = false;
		movingRight = false;
		movingLeft = true;
	}
	autoCut();
}

void Snake::autoCut() {
	for (int i = 1; i < length; i++) {
		if (body[0].x == body[i].x && body[0].y == body[i].y) {
			length = i - 1;
		}
	}
}

int Snake::getHeadX() const
{
	return body[0].x;
}

int Snake::getHeadY() const
{
	return body[0].y;
}