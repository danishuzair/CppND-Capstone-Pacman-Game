//
// Created by dansid on 4/1/20.
//

#include "Ghost.h"

Direction getRandomDirection() {
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<int> distr(0, 3);
    int action = distr(eng);
    switch (action){
        case (0):
            return Direction::left;
        case(1):
            return Direction::right;
        case(2):
            return Direction::up;
        case(3):
            return Direction::down;
    }
}

Ghost::Ghost(Color colorin, std::shared_ptr<TrafficObject> currentintersectionorstreet_in,
             Direction currentdirection_in, int startdelay_in):
             color(colorin),
             currentdirection(currentdirection_in),
             currentintersectionorstreet(currentintersectionorstreet_in),
             startdelay(startdelay_in)
{
    switch(color) {
        case(Color::red):
            xlocation = 253;
            ylocation = 228;
            break;
        case(Color::pink):
            xlocation = 253;
            ylocation = 288;
            break;
        case(Color::cyan):
            xlocation = 253;
            ylocation = 288;
            break;
        case(Color::orange):
            xlocation = 253;
            ylocation = 288;
            break;
        default:
            std::cerr<<"Invalid color received\n";
            break;
    }
}

void Ghost::updatePosition() {
    if (currentcycles >= startdelay) {
        if (currentintersectionorstreet->getType() != ObjectType::intersection) {

            std::shared_ptr<Street> currentstreet =
                    std::reinterpret_pointer_cast<Street>(currentintersectionorstreet);

            if (currentdirection == Direction::up) {
                ylocation -= speed;
            }
            else if (currentdirection == Direction::down) {
                ylocation += speed;
            }
            else if (currentdirection == Direction::left) {
                xlocation -= speed;
            }
            else if (currentdirection == Direction::right) {
                xlocation += speed;
            }

            std::shared_ptr<Intersection> newintersection =
                    currentstreet->checkifatintersection(xlocation,ylocation);
            if (newintersection != nullptr) {
                currentintersectionorstreet = newintersection;
            }
        }
        else {
            updateDirection();
        }
    }
    currentcycles+=1;
}

void Ghost::updateDirection() {
    std::shared_ptr<Intersection> currentintersection =
            std::reinterpret_pointer_cast<Intersection>(currentintersectionorstreet);
    std::shared_ptr<Street> newstreet = nullptr;
    Direction desireddirection = currentdirection;
    while (newstreet == nullptr) {
        desireddirection = getRandomDirection();
        switch(desireddirection) {
            case(Direction::right):
                newstreet = currentintersection->getRightStreet();
                break;
            case(Direction::left):
                newstreet = currentintersection->getLeftStreet();
                break;
            case(Direction::up):
                newstreet = currentintersection->getUpStreet();
                break;
            case(Direction::down):
                newstreet = currentintersection->getDownStreet();
                break;
        }
        if (newstreet != nullptr) {
            if (!newstreet->getAccessible()) {
                newstreet = nullptr;
            }
        }
    }
    currentintersectionorstreet = newstreet;
    currentdirection = desireddirection;
}
