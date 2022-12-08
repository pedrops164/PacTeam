#include <cmath>

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

int Position::manhattanDistance(Position endPos) {
	return std::abs(endPos.y - y) + std::abs(endPos.x - x);
}

bool Position::equals(Position pos) {
	return x == pos.x && y == pos.y;
}

Direction Position::getDirection(Position newPos) {
	Position neighbors[4] = {
			translate(Direction::Up),
			translate(Direction::Down),
			translate(Direction::Left),
			translate(Direction::Right)
	};
	if (newPos.equals(neighbors[0])) {
		return Direction::Up;
	}
	else if (newPos.equals(neighbors[1])) {
		return Direction::Down;
	}
	else if (newPos.equals(neighbors[2])) {
		return Direction::Left;
	}
	else if (newPos.equals(neighbors[3])) {
		return Direction::Right;
	}
	return Direction::Null;
}