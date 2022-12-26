#include "Ghost.h"

class DefaultGhost : public Ghost {
public:
	DefaultGhost(const DefaultGhost& g);
	DefaultGhost(int gId, int ticksPerMove, Position pos, Direction direction);
	Position getTargetPosition(Entity* pacman);
	virtual Ghost* clone();
};