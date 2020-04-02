//
// Created by dansid on 4/1/20.
//

#include "Street.h"
#include "Intersection.h"

void Street::initializeStreet(bool hasfood_in, bool hasfoodatstart, bool hasfoodatend, bool accessible_in,
                              std::shared_ptr<Intersection> startintersection_in,
                              std::shared_ptr<Intersection> endIntersection_in) {
    startintersection = startintersection_in;
    startintersection->connectStreet(get_shared_this());
    endintersection = endIntersection_in;
    endintersection->connectStreet(get_shared_this());
    accessible = accessible_in;
    if (startintersection->getLocationY() == endintersection->getLocationY()) {
        traveldirection = horizontal;
    }
    else {
        traveldirection = vertical;
    }
    hasfood = hasfood_in;
    if (hasfood) {
        if (traveldirection == horizontal) {
            SDL_Point food;
            food.y = startintersection->getLocationY();
            if (hasfoodatstart) {
                food.x = startintersection->getLocationX();
                foods.push_back(food);
            }
            for (int i = startintersection->getLocationX()+foodinterval; i<endintersection->getLocationX()-(foodinterval/2); i+=foodinterval) {
                food.x = i;
                foods.push_back(food);
            }
            if (hasfoodatend) {
                food.x = endintersection->getLocationX();
                foods.push_back(food);
            }
        }
        else {
            SDL_Point food;
            food.x = startintersection->getLocationX();
            if (hasfoodatstart) {
                food.y = startintersection->getLocationY();
                foods.push_back(food);
            }
            for (int i = startintersection->getLocationY()+foodinterval; i<endintersection->getLocationY()-(foodinterval/2); i+=foodinterval) {
                food.y = i;
                foods.push_back(food);
            }
            if (hasfoodatend) {
                food.y = endintersection->getLocationY();
                foods.push_back(food);
            }
        }
    }
}
