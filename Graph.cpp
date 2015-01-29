#include "Graph.h"

Graph::Graph(){
}

Graph::Graph(int _width, int _height){
	width = _width;
	height = _height;
	maze = new Node**[height];
	for (int i = 0; i < height; i++){
		maze[i] = new Node*[width];
		for (int j = 0; j < width; j++){
			maze[i][j] = new Node(i, j);
		}
	}

	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			if (i == 0){
				maze[i][j]->setNeighbour(UP, NULL);
			}
			else{
				maze[i][j]->setNeighbour(UP, maze[i - 1][j]);
			}
			if (i == height - 1){
				maze[i][j]->setNeighbour(DOWN, NULL);
			}
			else{
				maze[i][j]->setNeighbour(DOWN, maze[i + 1][j]);
			}
			if (j == 0){
				
				maze[i][j]->setNeighbour(LEFT, NULL);
			}
			else{
				maze[i][j]->setNeighbour(LEFT, maze[i][j - 1]);
			}
			if (j == width - 1){
				maze[i][j]->setNeighbour(RIGHT, NULL);
			}
			else{
				maze[i][j]->setNeighbour(RIGHT, maze[i][j + 1]);
			}
		}
	}

	/*for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			for (int k = 0; k < 4; k++){
				cout << maze[i][j]->getNeighbour(k) << " ";
			}
			cout << " ; ";
		}
		cout << endl;
	}*/

	int randRow = rand() % height;
	int randCol = rand() % width;

	maze[randRow][randCol]->setSearched(true);
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0, 100);
	while (maze[randRow][randCol]->hasUnsearchedNeightbours()){
		maze[randRow][randCol]->search(distribution(generator) % 4);
	}
	//cout << endl << endl;

	/*for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			for (int k = 0; k < 4; k++){
				cout << maze[i][j]->getNeighbour(k) << " ";
			}
			cout << " ; ";
		}
		cout << endl;
	}*/

	//cout << "----------------------------------------" << endl;
}


Graph::~Graph(){
	for (int i = 0; i < height; i++){
		delete[] maze[i];
	}
	delete[] maze;
}

void Graph::showGraph(){
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			cout << maze[i][j]->isSearched() << " ";
		}
		cout << endl;
	}
}

int Graph::getHeight(){
	return height;
}

int Graph::getWidth(){
	return width;
}

Node* Graph::getMazeNode(int i, int j){
	return maze[i][j];
}