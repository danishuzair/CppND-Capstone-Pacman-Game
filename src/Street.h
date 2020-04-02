//
// Created by dansid on 4/1/20.
//

#ifndef SDL2TEST_STREET_H
#define SDL2TEST_STREET_H

#include <vector>
#include "SDL.h"
#include <memory>
#include "TrafficObject.h"

class Intersection;

enum TravelDirection{vertical, horizontal};

class Street : public TrafficObject, public std::enable_shared_from_this<Street> {
public:
    void initializeStreet(bool hasfood_in, bool hasfoodatstart, bool hasfoodatend, bool accessible_in,
                          std::shared_ptr<Intersection> startintersection_in,
                          std::shared_ptr<Intersection> endIntersection_in);
    std::shared_ptr<Street> get_shared_this() { return shared_from_this(); }
    bool hasFood() const {return hasfood;}
    std::vector<SDL_Point>& getFood() {return foods;}

private:
    TravelDirection traveldirection;
    bool hasfood;
    bool accessible; // Is Pacman allowed to travel on this street
    std::vector<SDL_Point> foods;
    std::shared_ptr<Intersection> startintersection;
    std::shared_ptr<Intersection> endintersection;
};


#endif //SDL2TEST_STREET_H
