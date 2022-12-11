#ifndef _GHOST_

#define _GHOST_

#include "Entity.h"
#include "PieceBoard.h"

class Ghost : public Entity {
private:
	int ghostId;
public:
	Ghost(int gId, int ticksPerMove, Position pos, Direction direction);
	Direction getNextDirection(PieceBoard* pb, Entity* pacman);
};

#endif