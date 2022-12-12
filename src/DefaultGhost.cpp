#include "../libs/DefaultGhost.h"

DefaultGhost::DefaultGhost(int gId, int ticksPerMove, Position pos, Direction direction) 
	:Ghost(gId, ticksPerMove, pos, direction, Position(0,0)) {
}

Position DefaultGhost::getTargetPosition(Entity* pacman) {
	return pacman->getPosition();
}

