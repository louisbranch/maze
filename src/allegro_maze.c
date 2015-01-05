#include "maze.h"

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

const real32 FPS = 60.0f;
const int32 screen_width = 800;
const int32 screen_height = 600;

int main(int argc, char *argv[]) {

  ALLEGRO_DISPLAY *display = NULL;
  ALLEGRO_EVENT_QUEUE *event_queue = NULL;
  ALLEGRO_TIMER *timer = NULL;
  bool32 running = 1;
  bool32 redraw = 1;

  int32 x = 10;
  int32 y = 10;

  if (al_init()) {

    timer = al_create_timer(1.0 / FPS);
    display = al_create_display(screen_width, screen_height);
    event_queue = al_create_event_queue();
    redraw = 1;

    al_set_window_title(display, "Maze");
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_timer(timer);

    while (running) {
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);

      if (ev.type == ALLEGRO_EVENT_TIMER) {
        redraw = 1;
      } else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        running = 0;
      }

      if(redraw && al_is_event_queue_empty(event_queue)) {
        redraw = 0;
        al_clear_to_color(al_map_rgb(0,0,0));
        ALLEGRO_COLOR bg = al_map_rgba_f(1.0f,1.0f,1.0f,0);
        al_draw_filled_rectangle(x, y, x+30, y+30, bg);
        al_flip_display();
        x++;
        y++;
      }
    }

    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

  } else {
    //TODO log allegro initialization failed
  }

  return 0;
}
