#include <cmath>

#include "../libs/Position.h"

Position::Position(int x, int y) :
	x(x),
	y(y)
{
}

Position::Position() :
	x(-1),
	y(-1)
{
}

bool Position::operator == (const Position& coords) {
	return (x == coords.x && y == coords.y);
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
	case Null:
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
	return (x == pos.x) && (y == pos.y);
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

void Position::setX(int x, Position pos)
{
	pos.x = x;
}

double distanceCalculate(double x1, double y1, double x2, double y2)
{
	double x = x1 - x2; //calculating number to square in next step
	double y = y1 - y2;
	double dist;

	dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
	dist = sqrt(dist);                  

	return dist;
}