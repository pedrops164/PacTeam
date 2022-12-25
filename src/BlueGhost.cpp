#include "../libs/BlueGhost.h"

BlueGhost::BlueGhost(const BlueGhost& g) : Ghost(g) {

}

BlueGhost::BlueGhost(int gId, int ticksPerMove, Position position, Direction direction) 
	:Ghost(gId, ticksPerMove, position, direction, Position(0,0)) 
    {
}

Position BlueGhost::getTargetPosition(Entity* pacman) 
{
	if (isChaseMode()) 
    {
		return pacman->getPosition();
		//TODO return pacman->getBlueTarget();
	}
	else if (isScatterMode()) 
    {
		return scatterTarget; //TODO - SEE IF THE SCATTER TARGETS ARE OKAY
	}
	return Position(-1, -1);
	//the mode is scatter, this function shouldnt have been called
}

Ghost* BlueGhost::clone(){
	return new BlueGhost(*this);
}