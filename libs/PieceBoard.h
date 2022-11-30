#ifndef _PIECEBOARD_

#define _PIECEBOARD_

#include "Position.h"

enum Piece { Wall = 0, Food, BigFood, Empty };

class PieceBoard {
private:
	int width;
	int height;
	Piece* board; //matrix of Pieces
	bool* intersectionBoard;
	char pieceRepresentation[4];
	Piece getPiece(Position pos);
	void setPiece(Position pos, Piece piece);
public:
	PieceBoard(int w, int h);
	int getIndex(Position position);
	void setWall(Position pos);
	void setBigFood(Position pos);
	void setSmallFood(Position pos);
	void setEmpty(Position pos);
	char* getRepresentation();
	bool isWall(Position position);
	void generateIntersectionBoard();
	bool isIntersection(Position pos);
	bool isStraightTunel(Position pos);
	bool isCurveTunel(Position pos);
};


#endif // !_PIECEBOARD_
