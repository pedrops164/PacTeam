#include "../libs/Game.h"
#include <iostream>


Game::Game(std::string mapPath, int tPS, int ticksPlayer, int ticksGhosts) :
	board(Board(mapPath)),
	ticksPerSecond(tPS)
{
	ticksPerMovePlayer = ticksPlayer;
	ticksPerMoveGhosts = ticksGhosts;
	totalTicks = 0;
}

void Game::printBoard() {
	board.printBoard();
}

void Game::movePlayer() {
	board.movePlayer();
}

void Game::update() {
	if (totalTicks % ticksPerMovePlayer == 0) {
		//time to update Player
		board.updatePlayer();
	}
	if (totalTicks % ticksPerMoveGhosts == 0) {
		//time to update Ghosts
		std::cout << "teste" << std::endl;
		board.updateGhosts();
		std::cout << "teste1" << std::endl;
	}
	
	totalTicks += 1;
}
