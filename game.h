//
// Created by tayloryeow on 1/21/17.
//

#ifndef CODEMON_GAME_H
#define CODEMON_GAME_H

#define TILESIZE 40
#define T_WIDTH 21
#define T_HEIGHT 21

#define FPS 2


#define SCREEN_W TILESIZE * T_WIDTH
#define SCREEN_H TILESIZE * T_HEIGHT


enum MYKEYS {
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

enum DIRECTION {
    NORTH, EAST, SOUTH, WEST
};

#endif //CODEMON_GAME_H
