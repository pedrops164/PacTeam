#include "../libs/Position.h"

Position::Position(int x, int y) :
	x(x),
	y(y)
{
}

Position Position::translate(Direction direction) {
	int new_x = x;
	int new_y = y;
	switch (direction) {
	case Up:
		new_y -= 1;
		break;
	case Down:
		new_y += 1;
		break;
	case Right:
		new_x += 1;
		break;
	case Left:
		new_x -= 1;
		break;
	}
	return Position(new_x, new_y);
}

int Position::getX() {
	return x;
}

int Position::getY() {
	return y;
}