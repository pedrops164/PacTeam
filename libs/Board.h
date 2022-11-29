#ifndef _BOARD_

#define _BOARD_

#pragma once

#include <string>
#include <unordered_map>
#include "Entity.h"

enum Piece { Wall=0, Food, BigFood, Empty, Ghost1, Player };

class Board {
private:
	int width;
	int height;
	Piece* board; //matrix of Pieces
	char pieceRepresentation[6];
	Entity* player;
	Entity* ghosts[4];
	//std::unordered_map<int, Entity*> entities;
public:
	Board(std::string mapPath);
	float getIntervalPeriod();
	void printBoard();
	void movePlayer();
	void moveGhost(int id);
	bool isWall(Position position);
	Piece getPiece(Position position);
	void setPiece(Position position, Piece newPiece);
	int getIndex(Position position);
	void changeDirection(Entity* ent, Direction newDirection);
	void changePlayerDirection(Direction newDirection);
	void changeGhostDirection(int id, Direction newDirection);
	void updatePlayer();
};

#endif