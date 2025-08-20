#include <iostream>
#include <utility>
#include "../header_files/GameWindow.h"
#include "../header_files/RootObject.h"
#include "../header_files/RenderObject.h"
#include "../header_files/Sprite.h"
#include "../game/Player.h"

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
    static_assert(std::is_base_of_v<Object, T>, "T must derive from Object");
    auto object = new T{ this };
    objects.push_back(*object);
    return object;
}

template<typename T>
T* GameWindow::Create_Render_Object(std::string path) {
    static_assert(std::is_base_of_v<RenderObject, T>, "T must derive from RenderObject");
    auto render_object = new T{ this, std::move(path) };
    SDL_RenderTexture(sdl_renderer, render_object->texture, nullptr, nullptr);
    objects.push_back(*render_object);
    return render_object;
}

void GameWindow::Start() {
    const auto root = Create_Object<RootObject>();
    objects.push_back(*root);
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

template Sprite* GameWindow::Create_Render_Object<Sprite>(std::string path);
template Player* GameWindow::Create_Object<Player>();