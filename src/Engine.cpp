#include <iostream>
#include <SDL3/SDL.h>
#include "../header_files/Engine.h"
#include "../header_files/Time.h"

Engine::Engine() : game_window(800, 600) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL Init Failed: " << SDL_GetError() << '\n';
    }
}

void Engine::Run() const {
    Time time;

    bool running = true;
    while (running) {
        const bool* keys = SDL_GetKeyboardState(nullptr);
        SDL_PumpEvents();

        if (keys[SDL_SCANCODE_ESCAPE])
            running = false;

        game_window.Frame_Update();
    }
}
