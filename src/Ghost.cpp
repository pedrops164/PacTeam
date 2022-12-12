#include "../libs/Ghost.h"
#include "../libs/Astar.h"

Ghost::Ghost(int gId, int ticksPerMove, Position pos, Direction direction, Position scatter)
	:Entity(1, ticksPerMove, pos, direction) {
	ghostId = gId;
	mode = Mode::Chase;
	scatterTarget = scatter;
}

/*
* Receives the current state of the pieceBoard, and returns the next move
* for the ghost
* In this case, calls the A* algorithm, with origin in the ghost position,
* and destination in the pacman's position.
*/
Direction Ghost::getNextDirection(PieceBoard* pb, Entity* pacman) {
	Direction currentDirection = getDirection();
	Position previousPosition = getPosition().translate(opposite(currentDirection));
	Position endPosition = getTargetPosition(pacman);
	return Astar::getOptimalDirection(pb, getPosition(), endPosition, previousPosition);
}