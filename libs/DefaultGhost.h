#include "Ghost.h"

class DefaultGhost : public Ghost {
public:
	DefaultGhost(int gId, int ticksPerMove, Position pos, Direction direction);
	Position getTargetPosition(Entity* pacman);
};