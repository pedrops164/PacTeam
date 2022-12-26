#ifndef _POSITION_

#define _POSITION_
#include "Direction.h"

struct Position {
private:
	int x;
	int y;
public:
	Position();
	Position(int x, int y);
	Position translate(Direction direction);
	int getX();
	int getY();
	int manhattanDistance(Position endPos);
	bool equals(Position pos);
	Direction getDirection(Position newPos);
	bool operator == (const Position& coords);
	void setX(int x, Position pos);
	double distanceCalculate(double x1, double y1, double x2, double y2);
	Direction direction(Position endPos);
};

/*
class Position {
private:
	int x;
	int y;
public:
	Position();
	Position(int x, int y);
	Position translate(Direction direction);
	int getX();
	int getY();
	int manhattanDistance(Position endPos);
	bool equals(Position pos);
	Direction getDirection(Position newPos);
};
*/


#endif