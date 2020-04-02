//
// Created by dansid on 4/1/20.
//

#ifndef SDL2TEST_GHOST_H
#define SDL2TEST_GHOST_H

#include <iostream>
#include "SDL.h"

enum Color {red, pink, cyan, orange};

class Ghost {
public:
    Ghost(Color colorin);
    Color getColor() const{ return color;}
    int getLocationX () const{return location.x;}
    int getLocationY () const{return location.y;}
private:
    Color color;
    SDL_Point location;
};

#endif //SDL2TEST_GHOST_H
