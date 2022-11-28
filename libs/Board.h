#pragma once

#include <string>
#include <unordered_map>
#include "Entity.h"

enum Piece { Wall=0, Food, BigFood, Empty, Ghost, Player };

class Board {
private:
	int width;
	int height;
	Piece* board; //matrix of Pieces
	char pieceRepresentation[6];
	std::unordered_map<int, Entity*> entities;
	int playerId;
public:
	Board(std::string mapPath);
	float getIntervalPeriod();
	void printBoard();
	void move(int id);
	void move(int id, Direction newDirection);
	bool isWall(Position position);
	Piece getPiece(Position position);
	void setPiece(Position position, Piece newPiece);
	int getIndex(Position position);
	int getPlayerId();
};