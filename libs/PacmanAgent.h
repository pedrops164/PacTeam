#ifndef _PACMANAGENT_

#define _PACMANAGENT_

#include "Board.h"

class PacmanAgent {
public:
	virtual void updateState(Board* board) = 0;
};

#endif