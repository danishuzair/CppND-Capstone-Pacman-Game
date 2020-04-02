//
// Created by dansid on 4/1/20.
//

#ifndef CPPND_CAPSTONE_PACMAN_GAME_RENDERER_H
#define CPPND_CAPSTONE_PACMAN_GAME_RENDERER_H

#include <iostream>
#include <vector>
#include <string>
#include "SDL.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Intersection.h"
#include <memory>
#include "Street.h"

class Renderer {
public:
    Renderer (const std::size_t screen_width, const std::size_t screen_height, bool debugmode_in = false);
    ~Renderer();
    void Render(const Pacman &pacman, const std::vector<Ghost> &ghosts,
            std::vector<std::shared_ptr<Intersection>> &intersections,
            std::vector<std::shared_ptr<Street>> &streets);
    void UpdateWindowTitle(int score, int fps);

private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;
    SDL_Surface *sdl_surface;
    SDL_Texture *sdl_texture;
    bool debugmode;

    const std::size_t screen_width;
    const std::size_t screen_height;
};

#endif //CPPND_CAPSTONE_PACMAN_GAME_RENDERER_H
