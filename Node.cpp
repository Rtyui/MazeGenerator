#include "Node.h"


Node::Node(){
	row = 0;
	column = 0;
	neighbours = new Node*[NUM_SIDES];
	searched = false;
	for (int i = 0; i < NUM_SIDES; i++){
		neighbours[i] = NULL;
	}
}

Node::Node(int _row, int _column){
	row = _row;
	column = _column;
	neighbours = new Node*[NUM_SIDES];
	searched = false;
	a = 5;
}


Node::~Node(){
	delete neighbours;
}

int Node::getRow(){
	return row;
}

int Node::getColumn(){
	return column;
}

void Node::setSearched(bool setter){
	searched = setter;
}

int Node::reverseIndex(int index){
	switch (index)
	{
	case DOWN:
		return UP;
		break;
	case UP:
		return DOWN;
		break;
	case RIGHT:
		return LEFT;
		break;
	case LEFT:
		return RIGHT;
		break;
	default:
		return 0;
		break;
	}
}

bool Node::hasUnsearchedNeightbours(){
	for (int i = 0; i < NUM_SIDES; i++){
		if (neighbours[i] != NULL && !neighbours[i]->isSearched())
			return true;
	}
	return false;
}

void Node::deleteNeighbour(int index){
	neighbours[index] = NULL;
}

void Node::setNeighbour(int index, Node *n){
	neighbours[index] = n;
}

bool Node::isSearched(){
	return searched;
}

void Node::search(int index){
	if (neighbours[index] == NULL || neighbours[index]->isSearched()){
		return;
	}
	neighbours[index]->setSearched(true);

	default_random_engine generator;
	uniform_int_distribution<int> distrib(0, 1000);
	uniform_int_distribution<int> distribution(0, rand() % 1000);
	while (neighbours[index]->hasUnsearchedNeightbours()){
		neighbours[index]->search(distribution(generator) % 4);
		//neighbours[index]->search(LEFT );
		//neighbours[index]->search(DOWN);
		//neighbours[index]->search(distribution(generator));
		//neighbours[index]->search(UP);
		//neighbours[index]->search(RIGHT);
	}
	
	neighbours[index]->deleteNeighbour(reverseIndex(index));
	deleteNeighbour(index);
}

Node* Node::getNeighbour(int index){
	return neighbours[index];
}