#pragma once
#include "Graph.h"
class Square
{
public:
	float x;
	float y;
	float width;
	float height;
	int row;
	int column;
	bool *sides;
public:
	Square();
	Square(Node *n, float x, float y, float width, float height);
	~Square();

	void draw();
};

