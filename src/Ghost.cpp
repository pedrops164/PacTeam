#include "../libs/Ghost.h"

Ghost::Ghost(int gId, int nLives, int ticksPerMove, Position pos, Direction direction)
	:Entity(nLives, ticksPerMove, pos, direction) {
	ghostId = gId;
}