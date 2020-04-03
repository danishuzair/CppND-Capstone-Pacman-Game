//
// Created by dansid on 4/1/20.
//

#ifndef SDL2TEST_PACMAN_H
#define SDL2TEST_PACMAN_H

#include "SDL.h"
#include "memory"
#include "TrafficObject.h"
#include "Street.h"
#include "Intersection.h"

enum class Direction{left, right, up, down};

class Pacman {
public:
    Pacman(std::shared_ptr<TrafficObject> currentintersectionorstreet_in, Direction currentdirection_in);
    void updateDirection(Direction direction_new);
    int getLocationX () const{return xlocation;}
    int getLocationY () const{return ylocation;}
    int getScore() const {return score;}
    void updatePosition();
private:
    float speed{1.0f};
    float xlocation;
    float ylocation;
    int score = 0;
    Direction currentdirection;
    Direction newdirection;
    bool changedirection = false;
    std::shared_ptr<TrafficObject> currentintersectionorstreet;
};

#endif //SDL2TEST_PACMAN_H
