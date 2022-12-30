#ifndef __EVALUATION__

#define __EVALUATION__

#include <vector>

struct Evaluation {
private:
	std::vector<int> ev_list;
public:
	Evaluation(std::vector<int> evaluations);
	Evaluation(int eval);
	int compare(Evaluation e2);
	int getEvaluation(int index);
};

#endif