#include <iostream>
#include "Renderer.h"
#include "Game.h"
#include "Controller.h"
#include "Pacman.h"
#include "Ghost.h"
#include <vector>
#include <memory>
#include "Intersection.h"
#include "CreateTraversableArea.h"
#include "Street.h"

int main() {
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{512};
    constexpr std::size_t kScreenHeight{640};

    std::vector<std::shared_ptr<Intersection>> intersections;
    std::vector<std::shared_ptr<Street>> streets;
    CreateTraffic(intersections, streets);

    Renderer renderer(kScreenWidth, kScreenHeight, false);
    Controller controller;
    Pacman pacman;
    std::vector<Ghost> ghost;

    ghost.emplace_back(Ghost(red));
    ghost.emplace_back(Ghost(pink));
    ghost.emplace_back(Ghost(cyan));
    ghost.emplace_back(Ghost(orange));
    Game game;
    game.Run(controller, renderer, pacman, ghost, intersections, streets, kMsPerFrame);
    return 0;
}