#pragma once

#include "Position.h"
#include "Direction.h"

class Entity {
private:
	int id; //unique id of entity
	int nLives; //number of lives
	int ticksPerMove; //if the value is 1, it means the entity moves every tick.
	Position pos;
	Direction direction;
public:
	Entity(int id, int nLives, int ticksPerMove, Position pos, Direction direction);
	Entity();
	int getId();
	Direction getDirection();
	Position getPosition();
	void setPosition(Position position);
	void setDirection(Direction newDirection);
	void print();
};