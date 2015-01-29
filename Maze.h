#pragma once

#include "Graph.h"
#include "Square.h"
class Maze
{
private:
	Graph *mazeGraph;
	Square ***maze;
public:
	Maze();
	Maze(ALLEGRO_DISPLAY *display);
	~Maze();

	void draw();
};

