//
// Created by dansid on 4/1/20.
//

#ifndef SDL2TEST_INTERSECTION_H
#define SDL2TEST_INTERSECTION_H

#include "SDL.h"
#include "TrafficObject.h"
#include <memory>
#include <vector>
#include <iostream>

class Street;

class Intersection : public TrafficObject {
public:
    Intersection(){
        type = ObjectType::intersection;
    }
    void setLocation(int x, int y);
    int getLocationX () const{return location.x;}
    int getLocationY () const{return location.y;}
    std::shared_ptr<Street> getLeftStreet() const {return leftStreet;}
    std::shared_ptr<Street> getRightStreet() const {return rightStreet;}
    std::shared_ptr<Street> getUpStreet() const {return upStreet;}
    std::shared_ptr<Street> getDownStreet() const {return downStreet;}
    void connectStreet(std::shared_ptr<Street> connectedstreets_in);
    int eatFood();
private:
    bool connectWhenStreetGoesAcrossGuiEdge(std::shared_ptr<Street> connectedstreets_in);
    void connectHorizontalStreet(std::shared_ptr<Street> connectedstreets_in, double x);
    void connectVerticalStreet(std::shared_ptr<Street> connectedstreets_in, double y);
    int checkAndEatFood(std::shared_ptr<Street> street);
    SDL_Point location;
    std::shared_ptr<Street> leftStreet = nullptr;
    std::shared_ptr<Street> rightStreet = nullptr;
    std::shared_ptr<Street> upStreet = nullptr;
    std::shared_ptr<Street> downStreet = nullptr;
};


#endif //SDL2TEST_INTERSECTION_H
