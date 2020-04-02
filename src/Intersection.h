//
// Created by dansid on 4/1/20.
//

#ifndef SDL2TEST_INTERSECTION_H
#define SDL2TEST_INTERSECTION_H

#include "SDL.h"
#include "TrafficObject.h"
#include <memory>
#include <vector>

class Street;

class Intersection : public TrafficObject {
public:
    void setLocation(int x, int y);
    int getLocationX () const{return location.x;}
    int getLocationY () const{return location.y;}
    void connectStreet(std::shared_ptr<Street> connectedstreets_in);
private:
    SDL_Point location;
    std::vector<std::shared_ptr<Street>> connectedstreets;

};


#endif //SDL2TEST_INTERSECTION_H
