//
// Created by dansid on 4/1/20.
//

#include "Renderer.h"

Renderer::Renderer (const std::size_t screen_width, const std::size_t screen_height, bool debugmode_in):
                    screen_height(screen_height),
                    screen_width(screen_width),
                    debugmode(debugmode_in){
    // Initialize (SDL)
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create Window
    sdl_window = SDL_CreateWindow("PacMan Game", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, screen_width,
                                  screen_height, SDL_WINDOW_SHOWN);

    if (sdl_window == nullptr) {
        std::cerr << "Window could not be created.\n";
        std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create renderer
    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (sdl_renderer == nullptr) {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    sdl_surface = SDL_LoadBMP("../images/pacmanbackground.bmp");
    if (sdl_surface == nullptr) {
        std::cerr << "Image could not be loaded.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    sdl_texture = SDL_CreateTextureFromSurface(sdl_renderer, sdl_surface);
    if (sdl_texture == nullptr) {
        std::cerr << "Texture could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    SDL_RenderCopy(sdl_renderer, sdl_texture, NULL, NULL);
    SDL_RenderPresent(sdl_renderer);

}

Renderer::~Renderer() {
    SDL_DestroyTexture(sdl_texture);
    SDL_FreeSurface(sdl_surface);
    SDL_DestroyRenderer(sdl_renderer);
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}

void Renderer::Render(const Pacman &pacman, const std::vector<Ghost> &ghosts,
        std::vector<std::shared_ptr<Intersection>> &intersections,
        std::vector<std::shared_ptr<Street>> &streets) {
    // Clear Screen
    SDL_RenderClear(sdl_renderer);

    // Copying the PacMan background image
    SDL_RenderCopy(sdl_renderer, sdl_texture, NULL, NULL);

    SDL_Rect block;

    // Displaying the Pacman
    block.x = pacman.getLocationX();
    block.y = pacman.getLocationY();
    block.w = 20;
    block.h = 20;
    SDL_SetRenderDrawColor(sdl_renderer,0xFF, 0xFF, 0x00, 0xFF);
    SDL_RenderFillRect(sdl_renderer, &block);

    // Displaying the ghosts
    for (const Ghost& ghost : ghosts) {
        block.x = ghost.getLocationX();
        block.y = ghost.getLocationY();
        Color color = ghost.getColor();
        switch(color) {
            case(red):
                SDL_SetRenderDrawColor(sdl_renderer,0xFF, 0x00, 0x00, 0xFF);
                SDL_RenderFillRect(sdl_renderer, &block);
                break;
            case(pink):
                SDL_SetRenderDrawColor(sdl_renderer,0xFF, 0xB6, 0xC1, 0xFF);
                SDL_RenderFillRect(sdl_renderer, &block);
                break;
            case(cyan):
                SDL_SetRenderDrawColor(sdl_renderer,0x00, 0xFF, 0xFF, 0xFF);
                SDL_RenderFillRect(sdl_renderer, &block);
                break;
            case(orange):
                SDL_SetRenderDrawColor(sdl_renderer,0xFF, 0xA5, 0x00, 0xFF);
                SDL_RenderFillRect(sdl_renderer, &block);
                break;
        }
    }

    SDL_SetRenderDrawColor(sdl_renderer,0x00, 0x80, 0x00, 0xFF);
    block.w = 5;
    block.h = 5;
    for (const auto &street : streets) {
        if (street->hasFood()) {
            for (const auto &food: street->getFood()) {
                block.x = food.x;
                block.y = food.y;
                SDL_RenderFillRect(sdl_renderer, &block);
            }
        }
    }

    if (debugmode) {
        block.w = 10;
        block.h = 10;
        SDL_SetRenderDrawColor(sdl_renderer,0xF5, 0xE0, 0x50, 0xFF);
        for (const auto &intersection : intersections) {
            block.x = intersection->getLocationX();
            block.y = intersection->getLocationY();
            SDL_RenderFillRect(sdl_renderer, &block);
        }
    }

    // Update Screen
    SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
    std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
    SDL_SetWindowTitle(sdl_window, title.c_str());
}
