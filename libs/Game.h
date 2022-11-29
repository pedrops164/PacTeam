#ifndef _GAME_

#define _GAME_

#include "Board.h"

class Game {
private:
	Board board;
	float intervalPeriod; //time between screen updates
	int totalTicks;
	int ticksPerMovePlayer; //if the value is 1, it means the player moves every tick.
	int ticksPerMoveGhosts;
public:
	Game(std::string mapPath, float interval, int ticksPlayer, int ticksGhosts);
	void printBoard();
	void movePlayer();
	void update();
};

#endif