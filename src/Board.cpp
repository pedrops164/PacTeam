#include "../libs/Board.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Board::Board(string path, float interval) : pieceRepresentation{'#', '.', 'o', ' '}{
	
	intervalPeriod = interval;
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
			}
		}
	}
}

float Board::getIntervalPeriod() {
	return intervalPeriod;
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