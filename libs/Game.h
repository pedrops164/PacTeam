#ifndef _GAME_

#define _GAME_

#include "Board.h"

class Game {
private:
	Board board;
	int ticksPerSecond;
	int totalTicks;
	int ticksPerMovePlayer; //if the value is 1, it means the player moves every tick.
	int ticksPerMoveGhosts;
public:
	Game(std::string mapPath, int tPS, int ticksPlayer, int ticksGhosts);
	void printBoard();
	void movePlayer();
	void update();
};

#endif