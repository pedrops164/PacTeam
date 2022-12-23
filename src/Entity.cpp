#include "../libs/Entity.h"
#include <iostream>

Entity::Entity(int nLives, int ticksPerMove, Position pos, Direction direction):
	nLives(nLives),
	ticksPerMove(ticksPerMove),
	pos(pos),
	direction(direction)
{
}

Entity::Entity():
	id(-1),
	nLives(-1),
	ticksPerMove(-1),
	pos(Position(-1,-1))
{
}

int Entity::getId() {
	return id;
}

Direction Entity::getDirection() {
	return direction;
}

Position Entity::getPosition() {
	return pos;
}

void Entity::setPosition(Position position) {
	pos = position;
}

void Entity::setDirection(Direction newDirection) {
	direction = newDirection;
}

void Entity::print() {
	std::cout << id << "," << nLives << ",(" << pos.getX() << "," << pos.getY() << ")" << std::endl;
}


Position Entity::getPinkTarget()
{
	int newx = pos.getX()+4;
	pos.setX(newx, pos);
	return pos;
}
