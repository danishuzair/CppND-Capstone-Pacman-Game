//
// Created by dansid on 4/1/20.
//

#ifndef SDL2TEST_CONTROLLER_H
#define SDL2TEST_CONTROLLER_H

#include "SDL.h"
#include "Pacman.h"

class Controller{
public:
    void HandleInput(bool &running, Pacman &pacman) const;
};

#endif //SDL2TEST_CONTROLLER_H
