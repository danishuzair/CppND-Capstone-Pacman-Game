
#include "ManualController.h"

void ManualController::GetNewInput(bool &running, Pacman &pacman) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
        }
        else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_UP:
                    pacman.updateDirection(Direction::up);
                    break;
                case SDLK_DOWN:
                    pacman.updateDirection(Direction::down);
                    break;
                case SDLK_LEFT:
                    pacman.updateDirection(Direction::left);
                    break;
                case SDLK_RIGHT:
                    pacman.updateDirection(Direction::right);
                    break;
            }
        }
    }
}