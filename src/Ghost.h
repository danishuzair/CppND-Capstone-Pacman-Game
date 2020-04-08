//
// Created by dansid on 4/1/20.
//

#ifndef SDL2TEST_GHOST_H
#define SDL2TEST_GHOST_H

#include <iostream>
#include "SDL.h"
#include "TrafficObject.h"
#include <memory>
#include "Pacman.h"
#include <random>

enum class Color {red, pink, cyan, orange};

Direction getRandomDirection();

class Ghost {
public:
    Ghost(Color colorin, std::shared_ptr<TrafficObject> currentintersectionorstreet_in,
          Direction currentdirection_in, int startdelay_in);
    Color getColor() const{ return color;}
    int getLocationX () const{return int(xlocation);}
    int getLocationY () const{return int(ylocation);}
    void updatePosition();
private:
    void updateDirection();
    int currentcycles{0};
    int startdelay;
    float speed{1.0f};
    float xlocation;
    float ylocation;
    Color color;
    std::shared_ptr<TrafficObject> currentintersectionorstreet;
    Direction currentdirection;
};

#endif //SDL2TEST_GHOST_H
