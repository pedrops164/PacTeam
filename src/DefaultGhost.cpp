#include "../libs/DefaultGhost.h"

DefaultGhost::DefaultGhost(int gId, int ticksPerMove, Position pos, Direction direction) 
	:Ghost(gId, ticksPerMove, pos, direction, Position(0,0)) {
}

Position DefaultGhost::getTargetPosition(Entity* pacman) {
	if (isChaseMode()) {
		return pacman->getPosition();
	}
	else if (isScatterMode()) {
		return scatterTarget;
	}
	return Position(-1, -1);
	//the mode is scatter, this function shouldnt have been called
}

