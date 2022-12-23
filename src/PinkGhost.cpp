#include "../libs/PinkGhost.h"

PinkGhost::PinkGhost(int gId, int ticksPerMove, Position position, Direction direction) 
	:Ghost(gId, ticksPerMove, position, direction, Position(0,0)) 
    {
}

Position PinkGhost::getTargetPosition(Entity* pacman) 
{
	if (isChaseMode()) 
    {
		return pacman->getPinkTarget();
	}
	else if (isScatterMode()) 
    {
		return scatterTarget; //TODO - SEE IF THE SCATTER TARGETS ARE OKAY
	}
	return Position(-1, -1);
	//the mode is scatter, this function shouldnt have been called
}

