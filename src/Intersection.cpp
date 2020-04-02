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
    connectedstreets.push_back(connectedstreets_in);
}
