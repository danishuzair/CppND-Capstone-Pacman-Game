//
// Created by dansid on 4/1/20.
//

#ifndef SDL2TEST_PACMAN_H
#define SDL2TEST_PACMAN_H

#include "ScreenShot.h"
#include "SDL.h"
#include "memory"
#include "TrafficObject.h"
#include "Street.h"
#include "Intersection.h"
#include "Ghost.h"
#include <vector>

enum class Direction{left=0, right=1, up=2, down=3};
enum class PacmanState{newborn, secondlife, thirdlife, fourthlife, dead, victory};
class Ghost;

void PrintDirection(Direction direction);

class Pacman {
public:
    Pacman(std::shared_ptr<TrafficObject> currentintersectionorstreet_in, Direction currentdirection_in);
    void updateDirection(Direction direction_new);
    int getLocationX () const{return xlocation;}
    int getLocationY () const{return ylocation;}
    int getScore() const {return score;}
    void updatePosition();
    void updatestate(PacmanState pacmanstate_new);
    void updatepacmanandghoststates(std::vector<std::shared_ptr<Ghost>>  ghosts, ScreenShot &screenshot);
    PacmanState getCurrentState() const {return pacmanstate;}
    Direction getCurrentDirection() const {return currentdirection;}
    std::string getCurrentDirectionString() const;
    std::shared_ptr<TrafficObject> getCurrentIntersectionOrStreet() const {return currentintersectionorstreet;}
private:
    void resettoinitialstate(ScreenShot &screenshot);
    float speed{1.0f};
    float xlocation;
    float ylocation;
    int score = 0;
    Direction currentdirection;
    Direction newdirection;
    bool changedirection = false;
    std::shared_ptr<TrafficObject> currentintersectionorstreet;
    PacmanState pacmanstate;
    Direction startdirection;
    std::shared_ptr<TrafficObject> startintersectionorstreet;
};

#endif //SDL2TEST_PACMAN_H
