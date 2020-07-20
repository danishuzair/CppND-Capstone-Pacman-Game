//
// Created by dansid on 4/1/20.
//

#include "Game.h"

void Game::Run(Controller const *controller, Renderer &renderer, Pacman &pacman, std::vector<std::shared_ptr<Ghost>> ghosts,
        std::vector<std::shared_ptr<Intersection>> &intersections,
        std::vector<std::shared_ptr<Street>> &streets,
        std::size_t target_frame_duration) {
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;
    bool running = true;

    while (running) {
        frame_start = SDL_GetTicks();

        controller->GetNewInput(running, pacman);
        pacman.updatePosition();
        for (auto &ghost : ghosts) {
            ghost->updatePosition();
        }
        pacman.updatepacmanandghoststates(ghosts);
        renderer.Render(pacman, ghosts, intersections, streets);

        frame_end = SDL_GetTicks();

        // Keep track of how long each loop through the input / update / render cycle takes.
        frame_count++;
        frame_duration = frame_end - frame_start;

        // Updating title window after every second.
        if (frame_end - title_timestamp >= 1000) {
            score = pacman.getScore();
            renderer.UpdateWindowTitle(score, frame_count, pacman.getCurrentState());
            frame_count = 0;
            title_timestamp = frame_end;
        }

        // If frame_duration is smaller than target ms_per_frame, delay the loop to achieve desired frame rate
        if (frame_duration < target_frame_duration) {
            SDL_Delay(target_frame_duration - frame_duration);
        }
    }
}
