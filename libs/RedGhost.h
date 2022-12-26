#include "Ghost.h"

class RedGhost: public Ghost
{
public:
    RedGhost(const RedGhost& g);
    RedGhost(int gId, int ticksPerMove, Position position, Direction direction);
    Position getTargetPosition(Entity* pacman);
    virtual Ghost* clone();
};