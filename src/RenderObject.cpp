#include <iostream>
#include <SDL3_image/SDL_image.h>
#include "../header_files/RenderObject.h"

RenderObject::RenderObject(const char* path) {
    texture_path = path;
}

bool RenderObject::Buffer(GameWindow* window) {
    texture = IMG_LoadTexture(window->sdl_renderer, texture_path);

    if (!texture) {
        std::cerr << "Failed to load texture" << std::endl;
        return false;
    }

    return true;
}