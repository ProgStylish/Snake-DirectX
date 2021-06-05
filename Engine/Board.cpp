#include "Board.h"

Board::Board(int in_width, int in_height) :
	width(in_width),
	height(in_height)
{

}

void Board::draw(Graphics& gfx) {
	gfx.drawRect(Graphics::ScreenWidth/2, Graphics::ScreenHeight/2, width*10, height*10, 5, Colors::Red);
}
