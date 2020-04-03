//
// Created by dansid on 4/1/20.
//

#include "Street.h"
#include "Intersection.h"
#include "Pacman.h"

void Street::initializeStreet(bool hasfood_in, bool hasfoodatstart, bool hasfoodatend, bool accessible_in,
                              std::shared_ptr<Intersection> startintersection_in,
                              std::shared_ptr<Intersection> endIntersection_in) {
    startintersection = startintersection_in;
    endintersection = endIntersection_in;
    setAverage();
    setTravelDirection();
    accessible = accessible_in;
    startintersection->connectStreet(get_shared_this());
    endintersection->connectStreet(get_shared_this());
    hasfood = hasfood_in;
    setFood(hasfoodatstart,hasfoodatend);
}

void Street::setAverage() {
    average.x = (startintersection->getLocationX() + endintersection->getLocationX())/2;
    average.y = (startintersection->getLocationY() + endintersection->getLocationY())/2;
}

void Street::setTravelDirection() {
    if (startintersection->getLocationY() == endintersection->getLocationY()) {
        traveldirection = TravelDirection::horizontal;
    }
    else {
        traveldirection = TravelDirection::vertical;
    }
}

void Street::setFood(bool hasfoodatstart,bool hasfoodatend) {
    if (hasfood) {
        if (traveldirection == TravelDirection::horizontal) {
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

std::shared_ptr<Intersection> Street::checkifatintersection(float xlocation, float ylocation) {
    if (startintersection->getLocationX() == int(xlocation) && startintersection->getLocationY() == int(ylocation)) {
        return startintersection;
    }
    else if (endintersection->getLocationX() == int(xlocation) && endintersection->getLocationY() == int(ylocation)) {
        return endintersection;
    }
    else {
        return nullptr;
    }
}

bool Street::eatFood(float x, float y) {
    for (int i = 0; i < foods.size(); i++) {
        if (foods.at(i).x < int(x) + 5 && foods.at(i).x > int(x) - 5 &&
                foods.at(i).y < int(y) + 5 && foods.at(i).y > int(y) - 5) {
            foods.erase(foods.begin() + i);
            return true;
        }
    }
    return false;
}

IntersectionLocation Street::checkifclosetointersection(float x, float y) {
    if (startintersection->getLocationX() < int(x) + 20 &&
            startintersection->getLocationX() > int(x) - 20 &&
            startintersection->getLocationY() < int(y) + 20 &&
            startintersection->getLocationY() > int(y) - 20) {
        return IntersectionLocation::start;
    }
    else if (endintersection->getLocationX() == int(x) && endintersection->getLocationY() == int(y)) {
        return IntersectionLocation::end;
    }
    else {
        return IntersectionLocation::neither;
    }
}

bool Street::closetointersection(float x, float y, Direction direction) {
    IntersectionLocation  closeintersection = checkifclosetointersection(x,y);
    if (closeintersection == IntersectionLocation::neither) {
        return false;
    }
    switch (direction) {
        case Direction::left:
            if (closeintersection == IntersectionLocation::start) {
                if (startintersection->getLeftStreet() != nullptr) {
                    return true;
                }
            }
            else {
                if (endintersection->getLeftStreet() != nullptr) {
                    return true;
                }
            }
            break;
        case Direction::right:
            if (closeintersection == IntersectionLocation::start) {
                if (startintersection->getRightStreet() != nullptr) {
                    return true;
                }
            }
            else {
                if (endintersection->getRightStreet() != nullptr) {
                    return true;
                }
            }
            break;
        case Direction::up:
            if (closeintersection == IntersectionLocation::start) {
                if (startintersection->getUpStreet() != nullptr) {
                    return true;
                }
            }
            else {
                if (endintersection->getUpStreet() != nullptr) {
                    return true;
                }
            }
            break;
        case Direction::down:
            if (closeintersection == IntersectionLocation::start) {
                if (startintersection->getDownStreet() != nullptr) {
                    return true;
                }
            }
            else {
                if (endintersection->getDownStreet() != nullptr) {
                    return true;
                }
            }
            break;
    }
    return false;
}
