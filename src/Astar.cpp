#include "../libs/Astar.h"

Direction Astar::getOptimalDirection(PieceBoard* pb, Position currentPosition, Position endPosition) {
	std::vector<Node*> open, closed;
	open.reserve(100);
	closed.reserve(100);
	Node* currentNode = nullptr;
	int currentNodeIndex = 0;

	open.push_back(new Node(currentPosition));

	while (!open.empty()) {
		currentNode = open[0];
		for (int i = 0; i < open.size(); i++) {
			if (open[i]->getFcost() <= currentNode->getFcost()) {
				currentNode = open[i];
				currentNodeIndex = i;
			}
		}
		open.erase(open.begin() + currentNodeIndex);
		closed.push_back(currentNode);
		if (endPosition.equals(currentNode->pos)) break;

		Position neighbors[4] = {
			currentNode->pos.translate(Direction::Up),
			currentNode->pos.translate(Direction::Down),
			currentNode->pos.translate(Direction::Left),
			currentNode->pos.translate(Direction::Right)
		};
		for (int i = 0; i < 4; i++) {
			Position currentNeighbor = neighbors[i];
			//if the current neighbor position is a wall, or if he's in the closed list,
			//go to the next neighbor
			if (pb->isWall(currentNeighbor) || getNode(closed, currentNeighbor)) continue;

			int cost = currentNode->gcost + 1;
			
			Node* neighborNode = getNode(open, currentNeighbor);
			if (neighborNode == nullptr) {
				//the neighbor is not in the open list
				neighborNode = new Node(currentNeighbor, currentNode);
				neighborNode->gcost = cost;
				neighborNode->hcost = currentNeighbor.manhattanDistance(endPosition);
				open.push_back(neighborNode);
			}
			else if (cost < neighborNode->gcost) {
				neighborNode->parent = currentNode;
				neighborNode->gcost = cost;
			}
		}
	}
	std::vector<Position> positionList;
	while (currentNode != nullptr) {
		positionList.push_back(currentNode->pos);
		currentNode = currentNode->parent;
	}
	return positionList[0].getDirection(positionList[1]);
}

/*
* Gets a node list and a position, and returns the node with the given position,
* or returns nullptr if the list doesnt contain a node with this position
*/
Astar::Node* Astar::getNode(std::vector<Node*> nodeList, Position position) {
	for (Node* node : nodeList) {
		if (position.equals(node->pos)) {
			return node;
		}
	}
	return nullptr;
}

int Astar::Node::getFcost() {
	return hcost + gcost;
}

Astar::Node::Node(Position position, Node* parent):
	pos(position)
{
	hcost = gcost = 0;
	parent = parent;
}