//
// Created by dansid on 4/1/20.
//

#include "Pacman.h"

void PrintDirection(Direction direction) {
    switch(direction) {
        case(Direction::left):
            std::cout<<"left\n";
            break;
        case(Direction::right):
            std::cout<<"right\n";
            break;
        case(Direction::up):
            std::cout<<"up\n";
            break;
        case(Direction::down):
            std::cout<<"down\n";
            break;
    }
}

Pacman::Pacman(std::shared_ptr<TrafficObject> currentintersectionorstreet_in,
        Direction currentdirection_in) :
        currentdirection(currentdirection_in),
        currentintersectionorstreet(currentintersectionorstreet_in),
        startdirection(currentdirection_in),
        startintersectionorstreet(currentintersectionorstreet_in)
        {
    pacmanstate = PacmanState::newborn;
    xlocation = 248;
    ylocation = 473;
}

void Pacman::updateDirection(Direction direction_new) {
    if ((currentdirection == Direction::right || currentdirection == Direction::left) &&
            (direction_new == Direction::right || direction_new == Direction::left)) {
        currentdirection = direction_new;
        changedirection = false;
    }
    else if ((currentdirection == Direction::up || currentdirection == Direction::down) &&
             (direction_new == Direction::up || direction_new == Direction::down)) {
        currentdirection = direction_new;
        changedirection = false;
    }
    else if (currentdirection == Direction::right || currentdirection == Direction::left) {
        if (currentintersectionorstreet->getType() == ObjectType::intersection) {
            std::shared_ptr<Intersection> currentintersection =
                    std::reinterpret_pointer_cast<Intersection>(currentintersectionorstreet);
            if (direction_new == Direction::up) {
                std::shared_ptr<Street> newstreet = currentintersection->getUpStreet();
                if (newstreet != nullptr) {
                    if (newstreet->getAccessible()) {
                        currentdirection = direction_new;
                        currentintersectionorstreet = newstreet;
                        changedirection = false;
                    }
                }
            }
            else if (direction_new == Direction::down) {
                std::shared_ptr<Street> newstreet = currentintersection->getDownStreet();
                if (newstreet != nullptr) {
                    if (newstreet->getAccessible()) {
                        currentdirection = direction_new;
                        currentintersectionorstreet = newstreet;
                        changedirection = false;
                    }
                }
            }
        }
        else {
            std::shared_ptr<Street> currentstreet =
                    std::reinterpret_pointer_cast<Street>(currentintersectionorstreet);
            if (currentstreet->closetointersection(xlocation,ylocation,currentdirection,direction_new)) {
                changedirection = true;
                newdirection = direction_new;
            }
        }
    }
    else if (currentdirection == Direction::up || currentdirection == Direction::down) {
        if (currentintersectionorstreet->getType() == ObjectType::intersection) {
            std::shared_ptr<Intersection> currentintersection =
                    std::reinterpret_pointer_cast<Intersection>(currentintersectionorstreet);
            if (direction_new == Direction::right) {
                std::shared_ptr<Street> newstreet = currentintersection->getRightStreet();
                if (newstreet != nullptr) {
                    if (newstreet->getAccessible()) {
                        currentdirection = direction_new;
                        currentintersectionorstreet = newstreet;
                        changedirection = false;
                    }
                }
            }
            else if (direction_new == Direction::left) {
                std::shared_ptr<Street> newstreet = currentintersection->getLeftStreet();
                if (newstreet != nullptr) {
                    if (newstreet->getAccessible()) {
                        currentdirection = direction_new;
                        currentintersectionorstreet = newstreet;
                        changedirection = false;
                    }
                }
            }
        }
        else {
            std::shared_ptr<Street> currentstreet =
                    std::reinterpret_pointer_cast<Street>(currentintersectionorstreet);
            if (currentstreet->closetointersection(xlocation,ylocation,currentdirection,direction_new)) {
                changedirection = true;
                newdirection = direction_new;
            }
        }
    }
}

void Pacman::updatePosition() {
    if(pacmanstate == PacmanState::dead || pacmanstate == PacmanState::victory) {
        return;
    }
    switch (currentdirection) {
        case Direction::up:
            if(currentintersectionorstreet->getType() == ObjectType::intersection) {
                std::shared_ptr<Intersection> currentintersection =
                        std::reinterpret_pointer_cast<Intersection>(currentintersectionorstreet);
                score = score + currentintersection->eatFood() * 10;
                if (changedirection) {
                    changedirection = false;
                    if (newdirection == Direction::right) {
                        std::shared_ptr<Street> newstreet = currentintersection->getRightStreet();
                        if (newstreet ->getAccessible()) {
                            currentdirection = Direction::right;
                            xlocation += speed;
                            currentintersectionorstreet = newstreet;
                            if (newstreet->eatFood(xlocation,ylocation)) {
                                score +=10;
                            }
                        }
                    }
                    else if(newdirection == Direction::left) {
                        std::shared_ptr<Street> newstreet = currentintersection->getLeftStreet();
                        if (newstreet ->getAccessible()) {
                            currentdirection = Direction::left;
                            xlocation -= speed;
                            currentintersectionorstreet = newstreet;
                            if (newstreet->eatFood(xlocation,ylocation)) {
                                score +=10;
                            }
                        }
                    }
                    break;
                }
                std::shared_ptr<Street> newstreet = currentintersection->getUpStreet();
                if (newstreet != nullptr) {
                    if (newstreet->getAccessible()) {
                        ylocation -= speed;
                        currentintersectionorstreet = newstreet;
                        if (newstreet->eatFood(xlocation,ylocation)) {
                            score +=10;
                        }
                    }
                }
            }
            else {
                ylocation -= speed;
                std::shared_ptr<Street> currentstreet =
                        std::reinterpret_pointer_cast<Street>(currentintersectionorstreet);
                if (currentstreet->eatFood(xlocation,ylocation)) {
                    score +=10;
                }
                std::shared_ptr<Intersection> newintersection =
                        currentstreet->checkifatintersection(xlocation,ylocation);
                if (newintersection != nullptr) {
                    currentintersectionorstreet = newintersection;
                }
            }
            break;
        case Direction::down:
            if(currentintersectionorstreet->getType() == ObjectType::intersection) {
                std::shared_ptr<Intersection> currentintersection =
                        std::reinterpret_pointer_cast<Intersection>(currentintersectionorstreet);
                score = score + currentintersection->eatFood() * 10;
                if (changedirection) {
                    changedirection = false;
                    if (newdirection == Direction::right) {
                        std::shared_ptr<Street> newstreet = currentintersection->getRightStreet();
                        if (newstreet ->getAccessible()) {
                            currentdirection = Direction::right;
                            xlocation += speed;
                            currentintersectionorstreet = newstreet;
                            if (newstreet->eatFood(xlocation,ylocation)) {
                                score +=10;
                            }
                        }
                    }
                    else if(newdirection == Direction::left) {
                        std::shared_ptr<Street> newstreet = currentintersection->getLeftStreet();
                        if (newstreet ->getAccessible()) {
                            currentdirection = Direction::left;
                            xlocation -= speed;
                            currentintersectionorstreet = newstreet;
                            if (newstreet->eatFood(xlocation,ylocation)) {
                                score +=10;
                            }
                        }
                    }
                    break;
                }
                std::shared_ptr<Street> newstreet = currentintersection->getDownStreet();
                if (newstreet != nullptr) {
                    if (newstreet->getAccessible()) {
                        ylocation += speed;
                        currentintersectionorstreet = newstreet;
                        if (newstreet->eatFood(xlocation,ylocation)) {
                            score +=10;
                        }
                    }
                }
            }
            else {
                ylocation += speed;
                std::shared_ptr<Street> currentstreet =
                        std::reinterpret_pointer_cast<Street>(currentintersectionorstreet);
                if (currentstreet->eatFood(xlocation,ylocation)) {
                    score +=10;
                }
                std::shared_ptr<Intersection> newintersection =
                        currentstreet->checkifatintersection(xlocation,ylocation);
                if (newintersection != nullptr) {
                    currentintersectionorstreet = newintersection;
                }
            }
            break;
        case Direction::left:
            if(currentintersectionorstreet->getType() == ObjectType::intersection) {
                std::shared_ptr<Intersection> currentintersection =
                        std::reinterpret_pointer_cast<Intersection>(currentintersectionorstreet);
                score = score + currentintersection->eatFood() * 10;
                if (changedirection) {
                    changedirection = false;
                    if (newdirection == Direction::up) {
                        std::shared_ptr<Street> newstreet = currentintersection->getUpStreet();
                        if (newstreet ->getAccessible()) {
                            currentdirection = Direction::up;
                            ylocation -= speed;
                            currentintersectionorstreet = newstreet;
                            if (newstreet->eatFood(xlocation,ylocation)) {
                                score +=10;
                            }
                        }
                    }
                    else if(newdirection == Direction::down) {
                        std::shared_ptr<Street> newstreet = currentintersection->getDownStreet();
                        if (newstreet ->getAccessible()) {
                            currentdirection = Direction::down;
                            ylocation += speed;
                            currentintersectionorstreet = newstreet;
                            if (newstreet->eatFood(xlocation,ylocation)) {
                                score +=10;
                            }
                        }
                    }
                    break;
                }
                std::shared_ptr<Street> newstreet = currentintersection->getLeftStreet();
                if (newstreet != nullptr) {
                    if (newstreet->getAccessible()) {
                        if (newstreet->isconnecting()) {
                            float newxlocation;
                            float newylocation;
                            std::shared_ptr<Street> otherstreet =
                                    newstreet->getOtherStreet(xlocation,ylocation,newxlocation,newylocation,
                                                              Direction::left);
                            xlocation = newxlocation;
                            ylocation = newylocation;
                            newstreet = otherstreet;
                        }
                        xlocation -= speed;
                        currentintersectionorstreet = newstreet;
                        if (newstreet->eatFood(xlocation,ylocation)){
                            score +=10;
                        }
                    }
                }
            }
            else {
                xlocation -= speed;
                std::shared_ptr<Street> currentstreet =
                        std::reinterpret_pointer_cast<Street>(currentintersectionorstreet);
                if (currentstreet->eatFood(xlocation,ylocation)) {
                    score +=10;
                }
                std::shared_ptr<Intersection> newintersection =
                        currentstreet->checkifatintersection(xlocation,ylocation);
                if (newintersection != nullptr) {
                    currentintersectionorstreet = newintersection;
                }
            }
            break;
        case Direction::right:
            if(currentintersectionorstreet->getType() == ObjectType::intersection) {
                std::shared_ptr<Intersection> currentintersection =
                        std::reinterpret_pointer_cast<Intersection>(currentintersectionorstreet);
                score = score + currentintersection->eatFood() * 10;
                if (changedirection) {
                    changedirection = false;
                    if (newdirection == Direction::up) {
                        std::shared_ptr<Street> newstreet = currentintersection->getUpStreet();
                        if (newstreet ->getAccessible()) {
                            currentdirection = Direction::up;
                            ylocation -= speed;
                            currentintersectionorstreet = newstreet;
                            if (newstreet->eatFood(xlocation,ylocation)) {
                                score +=10;
                            }
                        }
                    }
                    else if(newdirection == Direction::down) {
                        std::shared_ptr<Street> newstreet = currentintersection->getDownStreet();
                        if (newstreet ->getAccessible()) {
                            currentdirection = Direction::down;
                            ylocation += speed;
                            currentintersectionorstreet = newstreet;
                            if (newstreet->eatFood(xlocation,ylocation)) {
                                score +=10;
                            }
                        }
                    }
                    break;
                }
                std::shared_ptr<Street> newstreet = currentintersection->getRightStreet();
                if (newstreet != nullptr) {
                    if (newstreet->getAccessible()) {
                        if (newstreet->isconnecting()) {
                            float newxlocation;
                            float newylocation;
                            std::shared_ptr<Street> otherstreet =
                                    newstreet->getOtherStreet(xlocation,ylocation,newxlocation,newylocation,
                                            Direction::right);
                            xlocation = newxlocation;
                            ylocation = newylocation;
                            newstreet = otherstreet;
                        }
                        xlocation += speed;
                        currentintersectionorstreet = newstreet;
                        if (newstreet->eatFood(xlocation,ylocation)) {
                            score +=10;
                        }
                    }
                }
            }
            else {
                xlocation += speed;
                std::shared_ptr<Street> currentstreet =
                        std::reinterpret_pointer_cast<Street>(currentintersectionorstreet);
                if (currentstreet->eatFood(xlocation,ylocation)) {
                    score +=10;
                }
                std::shared_ptr<Intersection> newintersection =
                        currentstreet->checkifatintersection(xlocation,ylocation);
                if (newintersection != nullptr) {
                    currentintersectionorstreet = newintersection;
                }
            }
            break;
    }
}

void Pacman::updatestate(PacmanState pacmanstate_new) {
    pacmanstate = pacmanstate_new;
}

void Pacman::updatepacmanandghoststates(std::vector<std::shared_ptr<Ghost>> ghosts, ScreenShot &screenshot) {
    bool collisiondetected = false;
    for (auto ghost : ghosts) {
        collisiondetected = ghost->checkForCollision(xlocation,ylocation);
        if (collisiondetected) {
            break;
        }
    }
    if (collisiondetected) {
        resettoinitialstate(screenshot);
        if(pacmanstate!=PacmanState::dead) {
            for (auto ghost : ghosts) {
                ghost->resettoinitialstate();
            }
        }
        else {
            for (auto ghost : ghosts) {
                ghost->settodeadstate();
            }
        }
    }

    if(score >= 1870) {
        updatestate(PacmanState::victory);
        for (auto ghost : ghosts) {
            ghost->settodeadstate();
        }
    }
}

void Pacman::resettoinitialstate(ScreenShot &screenshot) {
    screenshot.writeReward(-20);
    screenshot.updateRun();
    switch(pacmanstate) {
        case(PacmanState::newborn):
            pacmanstate = PacmanState::secondlife;
            break;
        case(PacmanState::secondlife):
            pacmanstate = PacmanState::thirdlife;
            break;
        case(PacmanState::thirdlife):
            pacmanstate = PacmanState::fourthlife;
            break;
        case(PacmanState::fourthlife):
            pacmanstate = PacmanState::dead;
            break;
    }
    if (pacmanstate != PacmanState::dead) {
        xlocation = 248;
        ylocation = 473;
        currentdirection = startdirection;
        currentintersectionorstreet = startintersectionorstreet;
    }
}

std::string Pacman::getCurrentDirectionString() const {
    switch (currentdirection) {
        case(Direction::left):
            return "left";
        case (Direction::right):
            return "right";
        case (Direction::up):
            return "up";
        case (Direction::down):
            return "down";
    }
}