#ifndef _ASTAR_

#define _ASTAR_

#include "Direction.h"
#include "PieceBoard.h"
#include "Position.h"
#include <vector>

namespace Astar {
	struct Node {
		Position pos;
		int hcost, gcost;
		Node* parent;
		Node(Position position, Node* parent = nullptr);
		int getFcost();
	};

	Direction getOptimalDirection(PieceBoard* pb, Position currentPosition, Position endPosition);

	Node* getNode(std::vector<Node*> nodeList, Position position);
}

#endif