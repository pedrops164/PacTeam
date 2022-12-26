#include "Ghost.h"

class BlueGhost: public Ghost
{
public:
    BlueGhost(const BlueGhost& g);
    BlueGhost(int gId, int ticksPerMove, Position position, Direction direction, int width);
    Position getTargetPosition(Entity* pacman, Ghost* redGhost);
    virtual Ghost* clone();
};