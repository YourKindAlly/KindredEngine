#include <SDL3_image/SDL_image.h>
#include "../header_files/RenderObject.h"

RenderObject::RenderObject(GameWindow* window, std::string path) : Object(window) {
    texture_path = path;
    texture = IMG_LoadTexture(window->sdl_renderer, texture_path.c_str());
}

void RenderObject::DestroySelf() {
    SDL_DestroyTexture(texture);

    for (const auto child : children) {
        child->DestroySelf();
    }

    delete this;
}