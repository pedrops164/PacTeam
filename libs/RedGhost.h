#include "Ghost.h"

class RedGhost: public Ghost
{
public:
    RedGhost(const RedGhost& g);
    RedGhost(int gId, int ticksPerMove, Position position, Direction direction, int width);
    Position getTargetPosition(Entity* pacman, Ghost* redGhost);
    virtual Ghost* clone();
};