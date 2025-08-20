#include <SDL3_image/SDL_image.h>
#include "../../header_files/Sprite.h"
#include "../../header_files/GameWindow.h"

Sprite::Sprite(GameWindow* window, std::string &path) : RenderObject(window, path) {
    texture_path = path;
    texture = IMG_LoadTexture(window->sdl_renderer, texture_path.c_str());
}
