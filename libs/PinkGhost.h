#include "Ghost.h"

class PinkGhost: public Ghost
{
    public:
    PinkGhost(int gId, int ticksPerMove, Position position, Direction direction);
    Position getTargetPosition(Entity* pacman);
};