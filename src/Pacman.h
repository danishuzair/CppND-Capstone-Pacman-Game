//
// Created by dansid on 4/1/20.
//

#ifndef SDL2TEST_PACMAN_H
#define SDL2TEST_PACMAN_H

#include "SDL.h"

class Pacman {
public:
    Pacman();
    int getLocationX () const{return location.x;}
    int getLocationY () const{return location.y;}

private:
    SDL_Point location;
};

#endif //SDL2TEST_PACMAN_H
