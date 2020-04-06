//
// Created by dansid on 4/1/20.
//

#include "Intersection.h"
#include "Street.h"

void Intersection::setLocation(int x, int y) {
    location.x = x;
    location.y = y;
}

void Intersection::connectStreet(std::shared_ptr<Street> connectedstreets_in) {
    SDL_Point average = connectedstreets_in->getAverage();
    if(connectedstreets_in->isconnecting()) {
        if(location.x < 50) {
            leftStreet = connectedstreets_in;
            return;
        }
        else {
            rightStreet = connectedstreets_in;
            return;
        }
    }
    if (connectedstreets_in->getTravelDirection() == TravelDirection::horizontal) {
        if (average.x > location.x) {
            rightStreet = connectedstreets_in;
        }
        else {
            leftStreet = connectedstreets_in;
        }
    }
    else {
        if (average.y > location.y) {
            downStreet = connectedstreets_in;
        }
        else {
            upStreet = connectedstreets_in;
        }
    }
}

int Intersection::eatFood() {
    int count = 0;
    if (upStreet != nullptr) {
        if (upStreet->eatFood(location.x,location.y)) {
            count += 1;
        }
    }
    if (downStreet != nullptr) {
        if (downStreet->eatFood(location.x,location.y)) {
            count += 1;
        }
    }
    if (leftStreet != nullptr) {
        if (leftStreet->eatFood(location.x,location.y)) {
            count += 1;
        }
    }
    if (rightStreet != nullptr) {
        if (rightStreet->eatFood(location.x,location.y)) {
            count += 1;
        }
    }
    return count;
}
