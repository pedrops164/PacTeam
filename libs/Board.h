#ifndef _BOARD_

#define _BOARD_

#pragma once

#include <string>
#include "Entity.h"
#include "Ghost.h"
#include "PieceBoard.h"


class Board {
private:
	int width;
	int height;
	PieceBoard* pieceBoard;
	Entity* player;
	Ghost* ghosts[4];
public:
	Board(std::string mapPath);
	void printBoard();
	void movePlayer();
	void moveGhost(int ghostId);
	void changePlayerDirection(Direction newDirection);
	void changeGhostDirection(int ghostId, Direction newDirection);
	void updatePlayer();
	void updateGhosts();
	void moveCurveTunnel(Entity* ghost);
	void setCurveDirection(Entity* ghost);
};

#endif