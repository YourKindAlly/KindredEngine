#include <SDL3_image/SDL_image.h>
#include "../header_files/RenderObject.h"
#include "../header_files/GameWindow.h"

RenderObject::RenderObject(GameWindow* window, const std::string& path) : Object(window) {
    texture_path = path;
    texture = IMG_LoadTexture(window->sdl_renderer, texture_path.c_str());
}

void RenderObject::Destroy_Self() {
    SDL_DestroyTexture(texture);

    for (const auto child : children) {
        child->Destroy_Self();
    }

    delete this;
}