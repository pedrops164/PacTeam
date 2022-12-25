#include "../libs/RedGhost.h"

RedGhost::RedGhost(const RedGhost& g) : Ghost(g) {

}

RedGhost::RedGhost(int gId, int ticksPerMove, Position position, Direction direction)
	:Ghost(gId, ticksPerMove, position, direction, Position(0,0)) 
    {
}

Position RedGhost::getTargetPosition(Entity* pacman) 
{
	if (isChaseMode()) 
    {
		return pacman->getPosition();
	}
	else if (isScatterMode()) 
    {
		return scatterTarget; //TODO - SEE IF THE SCATTER TARGETS ARE OKAYS
	}
	return Position(-1, -1);
	//the mode is scatter, this function shouldnt have been called
}

Ghost* RedGhost::clone() {
	return new RedGhost(*this);
}