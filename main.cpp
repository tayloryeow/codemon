//
// Created by tayloryeow on 1/21/17.
//

using namespace std;

#include <iostream>
#include <allegro5/allegro.h>

#define WAIT_TIME 1

//Todo display a grass tile
int main(int argc, char *argv[]){

    //Create the display!
    ALLEGRO_DISPLAY *display = NULL;
//    ALLEGRO_KEYBOARD *keyboard = NULL;

    //Initialize Allegro
    if(!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    //Create the main allegro display
    display = al_create_display(640, 480);
    if(!display) {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }

/*
    bool keyboard_init = al_install_keyboard();
    if (!keyboard_init){
        fprintf(stderr, "Keyboard failed to initialize!\n");
        return -1;
    }
*/

    al_clear_to_color(al_map_rgb(255, 255, 255));

    al_flip_display();

    al_rest(WAIT_TIME);

    al_destroy_display(display);

    return 0;

}


