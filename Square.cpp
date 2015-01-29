#include "Square.h"


Square::Square(){
}

Square::Square(Node *n, float _x, float _y, float w, float h){
	sides = new bool[NUM_SIDES];
	for (int i = 0; i < NUM_SIDES; i++){
		sides[i] = (n->getNeighbour(i) != NULL) ? true : false;
	}
	x = _x;
	y = _y;
	row = n->getRow();
	column = n->getColumn();
	width = w;
	height = h;
}

Square::~Square(){
	delete sides;
}

void Square::draw(){
	if (sides[UP]){ al_draw_line(x, y, x + width, y, al_map_rgb(255, 255, 255), 6);}
	if (sides[DOWN]){ al_draw_line(x, y + height, x + width, y + height, al_map_rgb(255, 255, 255), 6); }
	if (sides[LEFT]){ al_draw_line(x, y, x, y + height, al_map_rgb(255, 255, 255), 6); }
	if (sides[RIGHT]){ al_draw_line(x + width, y, x + width, y + height, al_map_rgb(255, 255, 255), 6); }
}
