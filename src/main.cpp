#include <iostream>
#include "Renderer.h"
#include "Game.h"
#include "ManualController.h"
#include "Pacman.h"
#include "Ghost.h"
#include <vector>
#include <memory>
#include "Intersection.h"
#include "CreateTraversableArea.h"
#include "Street.h"
#include "string.h"
#include <stdlib.h>
#include <array>
#include "CreateGameEnvironment.h"
#include "FollowMaximumFoodAutomatedController.h"

int main(int argc, char *argv[]) {

    int numberOfGhosts = 4;
    int mode = 0;
    for (int i=1; i<argc; i+=2) {
        if(!strcmp("-g",argv[i])) {
            numberOfGhosts = atoi(argv[i+1]);
        }
        if(!strcmp("-m",argv[i])) {
            mode = atoi(argv[i+1]);
        }
    }

    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{512};
    constexpr std::size_t kScreenHeight{640};

    std::vector<std::shared_ptr<Intersection>> intersections;
    std::vector<std::shared_ptr<Street>> streets;
    CreateTraffic(intersections, streets);

    Renderer renderer(kScreenWidth, kScreenHeight);

    FollowMaximumFoodAutomatedController automatedcontroller;
    ManualController manualcontroller;
    Controller *controller;
    controller = &automatedcontroller;
    if (mode == 1) {controller = &automatedcontroller;}
    else {controller = &manualcontroller;}

    Pacman pacman(streets.at(63),Direction::left);
    
    std::vector<Ghost> ghosts;
    initializeGhosts(ghosts,numberOfGhosts,streets);

    Game game;
    game.Run(controller, renderer, pacman, ghosts, intersections, streets, kMsPerFrame);
    return 0;
}