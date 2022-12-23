#include "../libs/Game.h"
#include <iostream>


Game::Game(std::string mapPath, int tPS, int ticksPlayer, int ticksGhosts, PacmanAgent* _pacmanAgent) :
	board(new Board(mapPath)),
	ticksPerSecond(tPS),
	pacmanAgent(_pacmanAgent)
{
	ticksPerMovePlayer = ticksPlayer;
	ticksPerMoveGhosts = ticksGhosts;
	totalTicks = 0;
}

void Game::printBoard() {
	board->printBoard();
}

void Game::update() {
	if (totalTicks % ticksPerMovePlayer == 0) {
		//time to update Player
		//board->updatePlayer();
		pacmanAgent->updateState(board);
	}
	if (totalTicks % ticksPerMoveGhosts == 0) {
		//time to update Ghosts
		board->updateGhosts();
	}
	
	totalTicks += 1;
}
