#ifndef _ENTITY_

#define _ENTITY_

#include "Position.h"
#include "Direction.h"

class Entity {
private:
	int id; //unique id of entity
	int nLives; //number of lives
	int ticksPerMove;
	Position pos;
	Direction direction;
public:
	Entity(const Entity& ent);
	Entity(int nLives, int ticksPerMove, Position pos, Direction direction);
	Entity();
	int getId();
	Direction getDirection();
	Position getPosition();
	Position getPinkTarget();
	Position getOrangeTarget();
	void setPosition(Position position);
	void setDirection(Direction newDirection);
	void print();
	Entity* clone();
};

#endif