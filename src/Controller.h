//
// Created by dansid on 4/1/20.
//

#ifndef SDL2TEST_CONTROLLER_H
#define SDL2TEST_CONTROLLER_H

#include "SDL.h"
#include "Pacman.h"

class Controller{
public:
    virtual void GetNewInput(bool &running, Pacman &pacman) const = 0;
    void attachGhosts(std::vector<std::shared_ptr<Ghost>> ghosts_in);
protected:
 	std::vector<std::shared_ptr<Ghost>> ghosts;
};

#endif //SDL2TEST_CONTROLLER_H
