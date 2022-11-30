#include "../libs/Ghost.h"

Ghost::Ghost(int gId, int ticksPerMove, Position pos, Direction direction)
	:Entity(1, ticksPerMove, pos, direction) {
	ghostId = gId;
}