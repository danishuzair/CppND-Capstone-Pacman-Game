//
// Created by dansid on 4/1/20.
//

#ifndef SDL2TEST_GAME_H
#define SDL2TEST_GAME_H

#include <iostream>
#include "Renderer.h"
#include "SDL.h"
#include "Controller.h"
#include "Pacman.h"
#include "Ghost.h"
#include <vector>
#include "Intersection.h"
#include <memory>
#include "Street.h"
#include <chrono>

class Game {
public:

    void Run(Controller *controller, Renderer &renderer, Pacman &pacman, std::vector<std::shared_ptr<Ghost>> ghosts,
            std::vector<std::shared_ptr<Intersection>> &intersections,
             std::vector<std::shared_ptr<Street>> &streets,
            std::size_t target_frame_duration, ScreenShot &screenshot);

private:
    int score{0};
};

#endif //SDL2TEST_GAME_H
