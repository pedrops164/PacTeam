#include "Ghost.h"

class BlueGhost: public Ghost
{
    public:
    BlueGhost(int gId, int ticksPerMove, Position position, Direction direction);
    Position getTargetPosition(Entity* pacman);
};