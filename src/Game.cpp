#include "../libs/Game.h"


Game::Game(std::string mapPath, float interval):
	board(Board(mapPath)),
	intervalPeriod(interval)
{
}

void Game::printBoard() {
	board.printBoard();
}

void Game::movePlayer() {
	int playerId = board.getPlayerId();
	board.move(playerId);
}

void Game::movePlayer(Direction direction) {
	int playerId = board.getPlayerId();
	board.move(playerId, direction);
}