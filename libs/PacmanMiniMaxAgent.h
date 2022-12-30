#include "Evaluation.h"
#include "PacmanAgent.h"
#include "EvaluationFunction.h"

class PacmanMiniMaxAgent : public PacmanAgent {
private:
	EvaluationFunction* ef;
public:
	PacmanMiniMaxAgent(EvaluationFunction* _ef);
	void updateState(Board* board);
	Evaluation minimax(Board* state, int depth, bool maximizingPlayer);
};