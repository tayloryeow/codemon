//
// Created by tayloryeow on 1/21/17.
//

#ifndef CODEMON_PLAYER_H
#define CODEMON_PLAYER_H
#include <allegro5/allegro.h>

#include "game.h"

#include <string>

class Character{
    int x, y;
    int width, height;
    int size;

    ALLEGRO_BITMAP *sprite;

    public:
        Character(int x, int y, int size){
            this->x = x * TILESIZE;
            this->y = y * TILESIZE;
            this->size = size;
        }

        void move(DIRECTION dir) {
            switch (dir) {
                case NORTH:
                    this->y += TILESIZE;
                    break;
                case EAST:
                    this->x += TILESIZE;
                    break;
                case SOUTH:
                    this->y -= TILESIZE;
                    break;
                case WEST:
                    this->x -= TILESIZE;
                    break;
            }
        }

        //Load Sprite from a bitmap
        void setSprite(ALLEGRO_BITMAP *sprite){
            this->sprite = sprite;
        }

        //Load Sprite from a string path
        void setSprite(const char *filename){
            ALLEGRO_PATH *path;
            al_change_directory(al_path_cstr(path, '/home/tayloryeow/ClionProjects/codemon/'));

            printf("%s\n", al_get_path_filename(path));

            printf("Right now, this program thinks the current working directory is \"%s\"\n",al_get_current_directory());
            this->sprite = al_load_bitmap(filename);
        }


        ALLEGRO_BITMAP* getSprite(){
            return this->sprite;
        }

        int getX(){
            return this->x;
        }

        int getY(){
            return this->y;
        }

        int getWidth(){
            return this->width;
        }

        int getHeight(){
            return this->height;
        }
};



#endif //CODEMON_PLAYER_H
