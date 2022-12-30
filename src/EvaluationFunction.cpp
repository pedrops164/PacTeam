#include "../libs/Evaluation.h"
#include "../libs/EvaluationFunction.h"
#include "../libs/BFS.h"
#include <iostream>

Evaluation EvaluationFunction::evaluate(Board* board) {
	//TODO
	int evaluation1 = board->getPoints();
	int evaluation2 = - BFS::getClosestPieceDistanceFromPacman(Piece::Food, board);
	std::vector<int> e;
	e.push_back(evaluation1);
	e.push_back(evaluation2);
	Evaluation ev = Evaluation(e);
	return ev;
}