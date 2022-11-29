#include "../libs/Board.h"
#include "../libs/Ghost.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

Board::Board(string path) : pieceRepresentation{'#', '.', 'o', ' ', 'M', '{'} {
	int currentGhostId = 0;
	ifstream map(path); //input file stream from path to the map text file
	if (!map) {
		//couldnt open file
		cout << "file not found!" << endl;
	}
	string currentLine;
	getline(map, currentLine);
	istringstream iss(currentLine);
	/*
	* First line of file is width and height of map
	* So first we get these values from the files and put in variables width and height
	*/
	iss >> width >> height; //set width and height parameters
	board = (Piece*) malloc(width * height * sizeof(Piece)); //we malloc the array with required space
	for (int j = 0; j < height; j++) {
		getline(map, currentLine);
		for (int i = 0; i < width; i++) {
			int currentIndex = j * height + i;
			if (currentLine[i] == '#') {
				board[currentIndex] = Piece::Wall;
			} else if (currentLine[i] == 'o') {
				board[currentIndex] = Piece::BigFood;
			} else if (currentLine[i] == '.') {
				board[currentIndex] = Piece::Food;
			} else if (currentLine[i] == ' ') {
				board[currentIndex] = Piece::Empty;
			} else if (currentLine[i] == 'M') {
				board[currentIndex] = Piece::Ghost1;
				Entity* ghost = new Ghost(currentGhostId, 1, 2, Position(i, j), Direction::Up);
				ghosts[currentGhostId] = ghost;
				currentGhostId++;
			} else if (currentLine[i] == '{') {
				board[currentIndex] = Piece::Player;
				player = new Entity(3, 1, Position(i, j), Direction::Right);
			}
		}
	}
}

void Board::printBoard() {
	char* representation = (char*) malloc(width * height * sizeof(char));
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			int currentIndex = j * height + i;
			Piece piece = board[currentIndex];
			representation[currentIndex] = pieceRepresentation[piece];
		}
	}
	//... set entities characters in representation matrix
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			int currentIndex = j * height + i;
			cout << representation[currentIndex];
		}
		cout << endl;
	}
	free(representation);
}

void Board::movePlayer() {
	Direction currentDirection = player->getDirection();
	Position currentPosition = player->getPosition();
	Position newPosition = currentPosition.translate(currentDirection);
	if (!isWall(newPosition)) {
		setPiece(newPosition, getPiece(currentPosition));
		setPiece(currentPosition, Empty);
		player->setPosition(newPosition);
	}
}

void Board::moveGhost(int id) {
	if (id > 3) {
		std::cout << "id de ghost invalido" << std::endl;
	}

	Entity* ghost = ghosts[id];
	Direction currentDirection = ghost->getDirection();
	Position currentPosition = ghost->getPosition();
	Position newPosition = currentPosition.translate(currentDirection);
	if (!isWall(newPosition)) {
		//need to do changes here. for example, ghosts dont eat food
		setPiece(newPosition, getPiece(currentPosition));
		setPiece(currentPosition, Empty);
		ghost->setPosition(newPosition);
	}
}
/*
* void Board::move(int id, Direction newDirection) {
	if (entities.find(id) != entities.end()) {
		Entity* ent = entities[id];
		Direction currentDirection = ent->getDirection();
		if (newDirection == currentDirection) {
			Board::move(id);
		}
		else {

			//Position currentPosition = ent->getPosition();
			//setPiece(currentPosition, (piece of new direction));
			ent->setDirection(newDirection);
		}
		
	}
	else {
		std::cout << "Entity id " << id << " doesnt exist";
	}
}
*/


bool Board::isWall(Position position) {
	int index = position.getY() * width + position.getX();
	return board[index] == Wall;
}

Piece Board::getPiece(Position position) {
	int index = getIndex(position);
	return board[index];
}

void Board::setPiece(Position position, Piece newPiece) {
	int index = getIndex(position);
	board[index] = newPiece;
}

int Board::getIndex(Position position) {
	return position.getY() * width + position.getX();
}

void Board::changePlayerDirection(Direction newDirection) {
	changeDirection(player, newDirection);
}

void Board::changeGhostDirection(int id, Direction newDirection) {
	changeDirection(ghosts[id], newDirection);
}

void Board::changeDirection(Entity* ent, Direction newDirection) {
	ent->setDirection(newDirection);
}

void Board::updatePlayer() {
	if (GetAsyncKeyState(VK_UP) & 1) {
		//Up arrow was clicked since last time
		player->setDirection(Direction::Up);
	}
	else if (GetAsyncKeyState(VK_DOWN) & 1) {
		player->setDirection(Direction::Down);
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 1) {
		player->setDirection(Direction::Right);
	}
	else if (GetAsyncKeyState(VK_LEFT) & 1) {
		player->setDirection(Direction::Left);
	}
	movePlayer();
}