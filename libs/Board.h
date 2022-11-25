#include <string>

enum Piece { Wall=0, Food, BigFood, Empty };

class Board {
private:
	int width;
	int height;
	Piece* board; //matrix of Pieces
	char pieceRepresentation[4];
	float intervalPeriod; //time between screen updates
public:
	Board(std::string mapPath, float interval);
	float getIntervalPeriod();
	void printBoard();
};