#include "../libs/Board.h"
#include "../libs/PieceBoard.h"
#include "../libs/Ghost.h"
#include "../libs/DefaultGhost.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

Board::Board(string path) {
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
	pieceBoard = new PieceBoard(width, height);
	for (int j = 0; j < height; j++) {
		getline(map, currentLine);
		for (int i = 0; i < width; i++) {
			Position position = Position(i, j);
			if (currentLine[i] == '#') {
				pieceBoard->setWall(position);
			} else if (currentLine[i] == 'o') {
				pieceBoard->setBigFood(position);
			} else if (currentLine[i] == '.') {
				pieceBoard->setSmallFood(position);
			} else if (currentLine[i] == ' ') {
				pieceBoard->setEmpty(position);
			} else if (currentLine[i] == 'M') {
				//board[currentIndex] = Piece::Ghost1;
				pieceBoard->setEmpty(position);
				Ghost* ghost = new DefaultGhost(currentGhostId, 2, Position(i, j), Direction::Right);
				ghosts[currentGhostId] = ghost;
				currentGhostId++;
			} else if (currentLine[i] == '{') {
				//board[currentIndex] = Piece::Player;
				pieceBoard->setEmpty(position);
				player = new Entity(3, 1, Position(i, j), Direction::Right);
			}
		}
	}
	pieceBoard->generateIntersectionBoard();
}

void Board::printBoard() {
	char* representation = pieceBoard->getRepresentation();

	//... set entities characters in representation 1d matrix
	Position playerPosition = player->getPosition ();
	representation[pieceBoard->getIndex(playerPosition)] = '{'; //change this later

	for (int j = 0; j < 4; j++) {
		Position ghostPosition = ghosts[j]->getPosition();
		representation[pieceBoard->getIndex(ghostPosition)] = 'M'; //change this later
	}

	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			int currentIndex = j * height + i;
			cout << representation[currentIndex];
		}
		cout << endl;
	}
	free(representation);
}

/*
* If the next position isn't a wall, moves the player in the current direction,
* eating the next piece (if there is)
*/
void Board::movePlayer() {
	Direction currentDirection = player->getDirection();
	Position currentPosition = player->getPosition();
	Position newPosition = currentPosition.translate(currentDirection);
	if (!pieceBoard->isWall(newPosition)) {
		//add the point system later
		if (pieceBoard->isBigFood(newPosition)) {
			for (int i = 0; i < 4; i++) {
				ghosts[i]->frighten();
			}
		}
		pieceBoard->setEmpty(newPosition);
		player->setPosition(newPosition);
	}
}

/*
* If the next position isn't a wall, moves the ghost in the current direction
*/
void Board::moveGhost(int ghostId) {
	Ghost* ghost = ghosts[ghostId];
	Direction currentDirection = ghost->getDirection();
	Position currentPosition = ghost->getPosition();
	Position newPosition = currentPosition.translate(currentDirection);
	if (!pieceBoard->isWall(newPosition)) {
		ghost->setPosition(newPosition);
	}
}

void Board::changePlayerDirection(Direction newDirection) {
	Position nextPosition = player->getPosition().translate(newDirection);
	if (!pieceBoard->isWall(nextPosition)) {
		player->setDirection(newDirection);
	}
}

void Board::changeGhostDirection(int ghostId, Direction newDirection) {
	ghosts[ghostId]->setDirection(newDirection);
}

/*
* Updates the position of every ghost
*/
void Board::updateGhosts() {

	for (int ghostId = 0; ghostId < 4; ghostId++) {
		Ghost* ghost = ghosts[ghostId];
		ghost->checkMode();
		Position ghostPos = ghost->getPosition();
		/*
		* Whatever the case is, the ghost can't go to the square
		* it was just in
		*/
		if (pieceBoard->isIntersection(ghostPos)) {
			/*
			* ghost is in an intersection
			* intersections have 3 or more surrounding squares 
			*/
			Direction newDirection = ghost->getNextDirection(pieceBoard, player);
			ghost->setDirection(newDirection);
			moveGhost(ghostId);
		} else if (pieceBoard->isDeadEnd(ghostPos)) {
			/*
			* In case of dead end, reverse the direction of the ghost
			*/
			ghost->setDirection(opposite(ghost->getDirection()));
			moveGhost(ghostId);
		} else {
			/*
			* ghost is in a tunel
			*
			* tunnels can be of type 1  # #   or of type 2  # #
			*						    #M#			        #M
			*						    # #			        ###
			* 
			*/
			if (pieceBoard->isStraightTunel(ghostPos)) {
				//ghost is in tunnel type 1 (straight line), so we just move the ghost
				moveGhost(ghostId);
			}
			else if (pieceBoard->isCurveTunel(ghostPos)) {
				//ghost is in tunnel type 2
				//so we change the direction of the ghost to the direction that has no wall, and we move 
				// the ghost
				setCurveDirection(ghost);
				moveGhost(ghostId);
			}
		}
	}
}

/*
* This function gets as input an entity that is assumed to be in a curved tunnel, and
* sets the direction of the entity to the direction that doesn't have a wall, in order
* for the entity to keep moving
*/
void Board::setCurveDirection(Entity* ghost) {
	//Assuming we are in a curve tunnel, this function gets as input the entity that is in a
	// type 2 tunnel, and retrieves the
	Position currentPosition = ghost->getPosition();
	Direction currentDirection = ghost->getDirection();
	//if the piece in the current direction isnt a wall, we dont change the direction
	Direction adjacent1, adjacent2;
	/*
	* If the entity's current direction is up or down, the positions to check are to the left
	* and to the right, and vice-versa.
	*/
	if (currentDirection == Direction::Up || currentDirection == Direction::Down) {
		adjacent1 = Direction::Left;
		adjacent2 = Direction::Right;
	}
	else {
		adjacent1 = Direction::Up;
		adjacent2 = Direction::Down;
	}

	Position pos1 = currentPosition.translate(adjacent1);
	//Position pos2 = currentPosition.translate(adjacent2);
	if (pieceBoard->isWall(pos1)) ghost->setDirection(adjacent2);
	else ghost->setDirection(adjacent1);
}