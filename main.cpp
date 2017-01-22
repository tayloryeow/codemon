#include <stdio.h>
#include <allegro5/allegro.h>

#include "player.h"
#include "game.h"

const int BOUNCER_SIZE = 32;

int main(int argc, char **argv){
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_BITMAP *p_sprite = NULL;
    
    bool redraw = true;

    if(!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }


    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    }

    display = al_create_display(SCREEN_W, SCREEN_H);
    if(!display) {
        fprintf(stderr, "failed to create display!\n");
        al_destroy_timer(timer);
        return -1;
    }

    p_sprite = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
    if(!p_sprite) {
        fprintf(stderr, "failed to create bouncer bitmap!\n");
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }


    al_set_target_bitmap(p_sprite);
    al_clear_to_color(al_map_rgb(255, 0, 255));
    al_set_target_bitmap(al_get_backbuffer(display));

    event_queue = al_create_event_queue();
    if(!event_queue) {
        fprintf(stderr, "failed to create event_queue!\n");
        al_destroy_bitmap(p_sprite);
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));


    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_timer(timer);

    Character player = Character(10, 10, TILESIZE);
    player.setSprite(p_sprite);
  //  player.setSprite("sprite.png");

    int i = 0;
    while(1)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER) {
            if (i == 0) {
                player.move(NORTH);
                i = 1;
            }
            else {
                player.move(SOUTH);
                i = 0;
            }
            redraw = true;
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }

        if(redraw && al_is_event_queue_empty(event_queue)) {
            redraw = false;

            al_clear_to_color(al_map_rgb(0,0,0));
            al_draw_bitmap(player.getSprite(), player.getX(), player.getY(), 0);
            al_flip_display();
        }
    }

    al_destroy_bitmap(p_sprite);
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}
