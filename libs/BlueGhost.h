#include "Ghost.h"

class BlueGhost: public Ghost
{
public:
    BlueGhost(const BlueGhost& g);
    BlueGhost(int gId, int ticksPerMove, Position position, Direction direction);
    Position getTargetPosition(Entity* pacman);
    Ghost* clone();
};