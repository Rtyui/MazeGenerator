#pragma once
#include <vector>
using namespace std;

#include "Node.h"
class Graph
{
private:
	Node ***maze;
	int width;
	int height;
public:
	Graph();
	Graph(int width, int height);
	~Graph();

	void showGraph();
	int getWidth();
	int getHeight();
	Node* getMazeNode(int i, int j);
};

