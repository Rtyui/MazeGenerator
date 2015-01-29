#include "Maze.h"

Maze::Maze(){
}

Maze::Maze(ALLEGRO_DISPLAY *display){
	int plm = rand() % 11;
	mazeGraph = new Graph(rand() % 8 + 3, rand() % 8 + 3);
	maze = new Square**[mazeGraph->getHeight()];
	for (int i = 0; i < mazeGraph->getHeight(); i++){
		maze[i] = new Square*[mazeGraph->getWidth()];
		for (int j = 0; j < mazeGraph->getWidth(); j++){
			maze[i][j] = new Square(mazeGraph->getMazeNode(i, j), al_get_display_width(display) / mazeGraph->getWidth() * j, al_get_display_height(display) / mazeGraph->getHeight() * i, al_get_display_width(display) / mazeGraph->getWidth(), al_get_display_height(display) / mazeGraph->getHeight());
		}
	}
}


Maze::~Maze(){
	for (int i = 0; i < mazeGraph->getHeight(); i++){
		for (int j = 0; j < mazeGraph->getWidth(); j++){
			delete maze[i][j];
		}
		delete[] maze[i];
	}
	delete[] maze;
}

void Maze::draw(){
	for (int i = 0; i < mazeGraph->getHeight(); i++){
		for (int j = 0; j < mazeGraph->getWidth(); j++){
			maze[i][j]->draw();
		}
	}
}
