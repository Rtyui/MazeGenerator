#include "Graph.h"
#include "Maze.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;

int main(int argc, char *argv[]){

	ALLEGRO_DISPLAY *display;
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *queue;
	ALLEGRO_EVENT event;

	al_init();
	al_install_keyboard();
	al_init_primitives_addon();

	display = al_create_display(WIDTH, HEIGHT);
	timer = al_create_timer(1 / 60.0);
	queue = al_create_event_queue();

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_keyboard_event_source());

	bool running = true;
	bool redraw = false;
	int counter = 0;
	Maze *maze = new Maze(display);

	al_start_timer(timer);
	while (running){
		al_wait_for_event(queue, &event);
		switch (event.type){
		case ALLEGRO_EVENT_TIMER:
			counter++;
			if (counter == 60){
				counter = 0;
				//maze = new Maze(display);
			}
			redraw = true;
			break;
		case ALLEGRO_EVENT_KEY_DOWN:
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
				running = false;
			}
			if (event.keyboard.keycode == ALLEGRO_KEY_R){
				maze = new Maze(display);
			}
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			running = false;
			break;
		}

		if (redraw){
			al_clear_to_color(al_map_rgb(0, 0, 0));
			maze->draw();
			al_flip_display();
		}
	}

	al_destroy_timer(timer);
	al_destroy_display(display);
	return 0;
}