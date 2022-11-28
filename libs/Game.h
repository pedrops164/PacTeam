#pragma once

#include "Board.h"

class Game {
private:
	Board board;
	float intervalPeriod; //time between screen updates
public:
	Game(std::string mapPath, float interval);
	void printBoard();
	void movePlayer();
	void movePlayer(Direction direction);
};