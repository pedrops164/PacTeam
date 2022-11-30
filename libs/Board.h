#ifndef _BOARD_

#define _BOARD_

#pragma once

#include <string>
#include "Entity.h"
#include "PieceBoard.h"


class Board {
private:
	int width;
	int height;
	PieceBoard* pieceBoard;
	Entity* player;
	Entity* ghosts[4];
public:
	Board(std::string mapPath);
	void printBoard();
	void movePlayer();
	void moveGhost(Entity* ghost);
	void changePlayerDirection(Direction newDirection);
	void updatePlayer();
	void updateGhosts();
	void moveCurveTunnel(Entity* ghost);
	void setCurveDirection(Entity* ghost);
};

#endif