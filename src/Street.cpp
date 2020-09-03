//
// Created by dansid on 4/1/20.
//

#include "Street.h"
#include "Intersection.h"
#include <cmath>

void Street::initializeStreet(bool hasfood_in, bool hasfoodatstart, bool hasfoodatend, bool accessible_in,
                              std::shared_ptr<Intersection> startintersection_in,
                              std::shared_ptr<Intersection> endIntersection_in,
                              bool connectingends_in) {
    connectingends = connectingends_in;
    startintersection = startintersection_in;
    endintersection = endIntersection_in;
    setAverage();
    setTravelDirection();
    setLength();
    accessible = accessible_in;
    startintersection->connectStreet(get_shared_this());
    endintersection->connectStreet(get_shared_this());
    hasfood = hasfood_in;
    setFood(hasfoodatstart,hasfoodatend);
}

bool Street::isGhostFound(Direction currentdirection,int x,int y,int xGhost, int yGhost) const {
    int xIntersection, yIntersection;
    FindIntersectionCoordinatesAtEndOfCurrentDirection(currentdirection, xIntersection, yIntersection);
    return findGhost(x,y,xIntersection,yIntersection,currentdirection,xGhost,yGhost);
}

bool Street::findGhost(int x, int y, int xIntersection, int yIntersection, Direction currentdirection,int xGhost, int yGhost) const{
    if (currentdirection == Direction::left || currentdirection == Direction::right) {
        if (yGhost != y) {return false;}
        if ((xGhost <= x && xGhost >=xIntersection) || (xGhost >= x && xGhost <=xIntersection)) {
            return true;
        }
    }
    else {
        if (xGhost != x) {return false;}
        if ((yGhost <= y && yGhost >=yIntersection) || (yGhost >= y && yGhost <=yIntersection)) {
            return true;
        }
    }
    return false;
}

void Street::FindIntersectionCoordinatesAtEndOfCurrentDirection(Direction currentdirection, int &x, int &y) const{
    int xStartIntersection = startintersection->getLocationX();
    int yStartIntersection = startintersection->getLocationY();
    int xEndIntersection = endintersection->getLocationX();
    int yEndIntersection = endintersection->getLocationY();
    if (currentdirection == Direction::down) {
        if (yStartIntersection > average.y){
            x = xStartIntersection,
            y = yStartIntersection;
        }
        else {
            x = xEndIntersection;
            y = yEndIntersection;
        }
    }
    else if (currentdirection == Direction::up) {
        if (yStartIntersection < average.y){
            x = xStartIntersection,
            y = yStartIntersection;
        }
        else {
            x = xEndIntersection;
            y = yEndIntersection;
        }
    }
    else if (currentdirection == Direction::left) {
        if (xStartIntersection < average.x){
            x = xStartIntersection,
            y = yStartIntersection;
        }
        else {
            x = xEndIntersection;
            y = yEndIntersection;
        }
    }
    else { // currentdirection::right
        if (xStartIntersection > average.x){
            x = xStartIntersection,
            y = yStartIntersection;
        }
        else {
            x = xEndIntersection;
            y = yEndIntersection;
        }
    }
}

void Street::setAverage() {
    average.x = (startintersection->getLocationX() + endintersection->getLocationX())/2;
    average.y = (startintersection->getLocationY() + endintersection->getLocationY())/2;
}

void Street::setLength() {
    if (traveldirection == TravelDirection::horizontal) {
        length = std::abs(endintersection->getLocationX() - startintersection->getLocationX());
    }
    else {
        length = std::abs(endintersection->getLocationY() - startintersection->getLocationY());
    }
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
    if (startintersection->getLocationX() == round(xlocation) && startintersection->getLocationY() == round(ylocation)) {
        return startintersection;
    }
    else if (endintersection->getLocationX() == round(xlocation) && endintersection->getLocationY() == round(ylocation)) {
        return endintersection;
    }
    else {
        return nullptr;
    }
}

bool Street::eatFood(float x, float y) {
    for (int i = 0; i < foods.size(); i++) {
        if (foods.at(i).x < round(x) + 5 && foods.at(i).x > round(x) - 5 &&
                foods.at(i).y < round(y) + 5 && foods.at(i).y > round(y) - 5) {
            foods.erase(foods.begin() + i);
            if(foods.empty()) {
                hasfood = false;
            }
            return true;
        }
    }
    return false;
}

IntersectionLocation Street::checkifclosetointersection(float x, float y, Direction direction) {
    if (direction == Direction::right && x < startintersection->getLocationX() && x > startintersection->getLocationX() -100) {
        return IntersectionLocation::start;
    }
    else if (direction == Direction::left && x > startintersection->getLocationX() && x < startintersection->getLocationX() +100) {
        return IntersectionLocation::start;
    }
    else if (direction == Direction::down && y < startintersection->getLocationY() && y > startintersection->getLocationY() -200) {
        return IntersectionLocation::start;
    }
    else if (direction == Direction::up && y > startintersection->getLocationY() && y < startintersection->getLocationY() +200) {
        return IntersectionLocation::start;
    }
    else if (direction == Direction::right && x < endintersection->getLocationX() && x > endintersection->getLocationX() -200) {
        return IntersectionLocation::end;
    }
    else if (direction == Direction::left && x > endintersection->getLocationX() && x < endintersection->getLocationX() +200) {
        return IntersectionLocation::end;
    }
    else if (direction == Direction::down && y < endintersection->getLocationY() && y > endintersection->getLocationY() -200) {
        return IntersectionLocation::end;
    }
    else if (direction == Direction::up && y > endintersection->getLocationY() && y < endintersection->getLocationY() +200) {
        return IntersectionLocation::end;
    }
    else {
        return IntersectionLocation::neither;
    }
}

bool Street::closetointersection(float x, float y, Direction currentdirection, Direction desireddirection) {
    IntersectionLocation  closeintersection = checkifclosetointersection(x,y, currentdirection);
    if (closeintersection == IntersectionLocation::neither) {
        return false;
    }
    switch (desireddirection) {
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

std::shared_ptr<Street> Street::getOtherStreet(float xlocation, float ylocation, float &newxlocation, float &newylocation,
                       Direction direction_in) {
    if (startintersection->getLocationX() == xlocation && startintersection->getLocationY() == ylocation) {
        newxlocation = endintersection->getLocationX();
        newylocation = endintersection->getLocationY();
        switch(direction_in) {
            case(Direction::right):
                return endintersection->getRightStreet();
            case(Direction::left):
                return endintersection->getLeftStreet();
            case(Direction::up):
                return endintersection->getUpStreet();
            case(Direction::down):
                return endintersection->getDownStreet();
        }
    }
    else {
        newxlocation = startintersection->getLocationX();
        newylocation = startintersection->getLocationY();
        switch(direction_in) {
            case(Direction::right):
                return startintersection->getRightStreet();
            case(Direction::left):
                return startintersection->getLeftStreet();
            case(Direction::up):
                return startintersection->getUpStreet();
            case(Direction::down):
                return startintersection->getDownStreet();
        }
    }
}

std::shared_ptr<Intersection> Street::getOtherIntersection(std::shared_ptr<Intersection> currentIntersection) const {
    if (currentIntersection->getLocationX() == startintersection->getLocationX() && 
        currentIntersection->getLocationY() == startintersection->getLocationY()) {
        return endintersection;
    }
    else {
        return startintersection;
    }
}

bool Street::checkifonstreet(int x, int y) const{
    if (traveldirection == TravelDirection::horizontal) {
        if (y != average.y) {
            return false;
        }
        int x1 = startintersection->getLocationX();
        int x2 = endintersection->getLocationX();
        if ((x <= x1 && x >= x2) || (x >= x1 && x <= x2)) {
            return true;
        }
        return false;
    }
    else {
        if (x != average.x) {
            return false;
        }
        int y1 = startintersection->getLocationY();
        int y2 = endintersection->getLocationY();
        if ((y <= y1 && y >= y2) || (y >= y1 && y <= y2)) {
            return true;
        }
        return false;
    }
}