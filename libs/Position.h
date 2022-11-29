#ifndef _POSITION_

#define _POSITION_
#include "Direction.h"

class Position {
private:
	int x;
	int y;
public:
	Position(int x, int y);
	Position translate(Direction direction);
	int getX();
	int getY();
};

#endif