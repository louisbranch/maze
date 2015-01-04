#include "maze.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main(int argc, char *argv[]) {

  if (al_init()) {

    ALLEGRO_DISPLAY *display = al_create_display(800,600);

    al_set_window_title(display, "Maze");

    ALLEGRO_COLOR bg = al_map_rgba_f(.5f,.5f,.5f, 0);

    al_draw_filled_rectangle(10, 10, 30, 30, bg);

    al_flip_display();

    while(1) {
    }

  } else {
    //TODO log allegro initialization failed
  }

  return 0;
}
