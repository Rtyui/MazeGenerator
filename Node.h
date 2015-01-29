#pragma once
#include <vector>
#include <random>
#include <cstdio>
#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>

using namespace std;
enum SIDES{LEFT, RIGHT, UP, DOWN, NUM_SIDES};

class Node
{
private:
	int a;
	Node **neighbours;
	int row;
	int column;
	bool searched;
public:
	Node();
	Node(int _row, int _col);
	~Node();

	int getRow();
	int getColumn();
	void setSearched(bool setter);
	void setNeighbour(int index, Node *n);
	int reverseIndex(int index);
	bool hasUnsearchedNeightbours();
	void deleteNeighbour(int index);
	bool isSearched();
	void search(int index);
	Node* getNeighbour(int index);
};

