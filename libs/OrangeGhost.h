#include "Ghost.h"

class OrangeGhost: public Ghost
{
public:
    OrangeGhost(const OrangeGhost& g);
    OrangeGhost(int gId, int ticksPerMove, Position position, Direction direction, int width);
    Position getTargetPosition(Entity* pacman, Ghost* redGhost);
    virtual Ghost* clone();
};