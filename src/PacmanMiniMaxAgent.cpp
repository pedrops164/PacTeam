#include "../libs/PacmanMiniMaxAgent.h"
#include <iostream>

PacmanMiniMaxAgent::PacmanMiniMaxAgent(EvaluationFunction* _ef) {
	ef = _ef;
}

void PacmanMiniMaxAgent::updateState(Board* board) {
	std::vector<Board*> possibleStates = board->getPacmanChildStates();
	int maxEval = INT_MIN;
	Board* bestState = nullptr;
	std::vector<Board*>::iterator it = possibleStates.begin();
	for (; it != possibleStates.end(); ++it) {
		Board* currState = *it;
		int currStateValue = minimax(currState, 3, false);
		if (currStateValue > maxEval) {
			maxEval = currStateValue;
			bestState = currState;
		}
	}
	//at this point, bestState contains the best possible next state for pacman

	Position currPos = board->getPacman()->getPosition();
	Position newPos = bestState->getPacman()->getPosition();
	Direction directionToTake = currPos.direction(newPos);
	board->changePlayerDirection(directionToTake);
	board->movePlayer();
}

int PacmanMiniMaxAgent::minimax(Board* state, int depth, bool maximizingPlayer) {
	if (depth == 0) {
		return ef->evaluate(state);
	}

	if (maximizingPlayer) {
		int maxEval = INT_MIN;
		std::vector<Board*> possibleStates = state->getPacmanChildStates();
		std::vector<Board*>::iterator it = possibleStates.begin();
		for (; it != possibleStates.end(); ++it) {
			Board* currState = *it;
			int currStateValue = minimax(currState, depth - 1, false);
			if (currStateValue > maxEval) maxEval = currStateValue;
		}
		return maxEval;
	}
	else {
		int minEval = INT_MAX;
		std::vector<Board*> possibleStates = state->getGhostsChildStates();
		std::vector<Board*>::iterator it = possibleStates.begin();
		for (; it != possibleStates.end(); ++it) {
			Board* currState = *it;
			int currStateValue = minimax(currState, depth - 1, true);
			if (currStateValue < minEval) minEval = currStateValue;
		}
		return minEval;
	}
}