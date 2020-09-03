//
// Created by dansid on 4/1/20.
//

#include "Intersection.h"
#include "Street.h"
#include "Pacman.h"

void Intersection::setLocation(int x, int y) {
    location.x = x;
    location.y = y;
}

bool Intersection::connectWhenStreetGoesAcrossGuiEdge(std::shared_ptr<Street> connectedstreets_in){
    if(connectedstreets_in->isconnecting() && location.x < 50) {
        leftStreet = connectedstreets_in;
        return true;
    }
    else if(connectedstreets_in->isconnecting()) {
        rightStreet = connectedstreets_in;
        return true;
    }
    return false;
}

void Intersection::connectHorizontalStreet(std::shared_ptr<Street> connectedstreets_in, double x){
    if (x > location.x) {
        rightStreet = connectedstreets_in;
    }
    else {
        leftStreet = connectedstreets_in;
    }
}

void Intersection::connectVerticalStreet(std::shared_ptr<Street> connectedstreets_in, double y){
    if (y > location.y) {
        downStreet = connectedstreets_in;
    }
    else {
        upStreet = connectedstreets_in;
    }
}

void Intersection::connectStreet(std::shared_ptr<Street> connectedstreets_in) {
    if (connectWhenStreetGoesAcrossGuiEdge(connectedstreets_in)) {return;}
    SDL_Point average = connectedstreets_in->getAverage();
    if (connectedstreets_in->getTravelDirection() == TravelDirection::horizontal) {
        connectHorizontalStreet(connectedstreets_in, average.x);
    }
    else{
        connectVerticalStreet(connectedstreets_in, average.y);
    }
}

int Intersection::checkAndEatFood(std::shared_ptr<Street> street){
    if (street == nullptr) {return 0;}
    if (street->eatFood(location.x,location.y)) {return 1;}
    return 0;
}

int Intersection::eatFood() {
    int count = 0;
    count += checkAndEatFood(upStreet);
    count += checkAndEatFood(downStreet);
    count += checkAndEatFood(leftStreet);
    count += checkAndEatFood(rightStreet);
    return count;
}

Direction Intersection::getDirectionToIntersection(int x, int y){
    if (x == location.x) {
        if (y > location.y) {
            return Direction::up;
        }
        else {
            return Direction::down;
        }
    }
    else { // y == location.y
        if (x > location.x) {
            return Direction::left;
        }
        else {
            return Direction::right;
        }
    }
}