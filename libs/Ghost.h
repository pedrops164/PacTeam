#ifndef _GHOST_

#define _GHOST_

#include "Entity.h"
#include "PieceBoard.h"

enum Mode {Chase, Scatter, Frightened};

/*
* Instances of class Ghost can't be instantiated, because there is an abstract method!
* Only classes that define this method can be instantiated.
*/
class Ghost : public Entity {
private:
	int ghostId;
	Mode mode;
	//position of the target of the ghosts when they're in scatter mode
	Position scatterTarget; 
public:
	Ghost(int gId, int ticksPerMove, Position pos, Direction direction, Position scatter);
	Direction getNextDirection(PieceBoard* pb, Entity* pacman);
	virtual Position getTargetPosition(Entity* pacman) = 0;
};

#endif