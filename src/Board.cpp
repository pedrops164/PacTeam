#include "../libs/Board.h"
#include "../libs/Entity.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Board::Board(string path) : pieceRepresentation{'#', '.', 'o', ' ', 'M', '{'} {
	int currentId = 0;
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
				board[currentIndex] = Piece::Ghost;
				Entity* ghost = new Entity(currentId, 1, 2, Position(i, j), Direction::Up);
				entities[currentId] = ghost;
				currentId++;
			} else if (currentLine[i] == '{') {
				board[currentIndex] = Piece::Player;
				Entity* player = new Entity(currentId, 3, 1, Position(i, j), Direction::Right);
				entities[currentId] = player;
				playerId = currentId;
				currentId++;
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

void Board::move(int id) {
	if (entities.find(id) != entities.end()) {
		Entity* ent = entities[id];
		Direction currentDirection = ent->getDirection();
		Position currentPosition = ent->getPosition();
		Position newPosition = currentPosition.translate(currentDirection);
		if (!isWall(newPosition)) {
			setPiece(newPosition, getPiece(currentPosition));
			setPiece(currentPosition, Empty);
			ent->setPosition(newPosition);
		}
	}
	else {
		std::cout << "Entity id " << id << " doesnt exist";
	}
}

void Board::move(int id, Direction newDirection) {
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

int Board::getPlayerId() {
	return playerId;
}
