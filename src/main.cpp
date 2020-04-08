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

    Renderer renderer(kScreenWidth, kScreenHeight);
    Controller controller;
    Pacman pacman(streets.at(63),Direction::left);
    std::vector<Ghost> ghosts;

    ghosts.emplace_back(Ghost(Color::red,streets.at(32),Direction::left,0));
    ghosts.emplace_back(Ghost(Color::pink,streets.at(36),Direction::up,120));
    ghosts.emplace_back(Ghost(Color::cyan,streets.at(36),Direction::up,240));
    ghosts.emplace_back(Ghost(Color::orange,streets.at(36),Direction::up,360));
    Game game;
    game.Run(controller, renderer, pacman, ghosts, intersections, streets, kMsPerFrame);
    return 0;
}