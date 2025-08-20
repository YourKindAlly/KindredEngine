#include <iostream>
#include "../header_files/GameWindow.h"
#include "../header_files/RootObject.h"
#include "../header_files/RenderObject.h"

GameWindow::GameWindow(int width, int height) : viewport(width, height) {
    sdl_window = SDL_CreateWindow("WINDOW_TITLE", viewport.Get_Width(), viewport.Get_Height(), 0);
    if (!sdl_window) {
        std::cerr << "Window Creation Failed: " << SDL_GetError() << '\n';
        SDL_Quit();
    }

    sdl_renderer = SDL_CreateRenderer(sdl_window, nullptr);
    if (!sdl_renderer) {
        std::cerr << "Renderer Creation Failed: " << SDL_GetError() << '\n';
        SDL_Quit();
    }

    scale_mode = SDL_SCALEMODE_NEAREST;
    Start();
}

template<typename T>
T* GameWindow::Create_Object() {
    std::unique_ptr<T> object;
    objects.push_back(object);
    return object;
}

void GameWindow::Start() {
    const auto root = std::make_shared<RootObject>();

    objects.push_back(root);

    for (std::shared_ptr object : root->children) {
        if (const auto render_object = dynamic_cast<RenderObject*>(object.get())) {
            render_object->Buffer(this);
            SDL_RenderTexture(sdl_renderer, render_object->texture, nullptr, nullptr);
        }

        objects.push_back(object);
    }
}

void GameWindow::Frame_Update() const {
    SDL_RenderClear(sdl_renderer);
    SDL_RenderPresent(sdl_renderer);
}

GameWindow::~GameWindow() {
    SDL_DestroyRenderer(sdl_renderer);
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}