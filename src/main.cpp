#include <iostream>
#include "../libs/Board.h"

int main() {
	Board board = Board("../maps/0.txt", 3);
	board.printBoard();

	return 0;
}