#include <SDL3_image/SDL_image.h>
#include "../header_files/RenderObject.h"
#include "../header_files/GameWindow.h"

RenderObject::RenderObject(GameWindow* window, std::string& path) : Object(window) {
    texture_path = path;
    texture = IMG_LoadTexture(window->sdl_renderer, texture_path.c_str());
}

void RenderObject::Set_Position(Vector2 position) {
    transform.position = position;
    dest_rect.x = position.x;
    dest_rect.y = position.y;
}


void RenderObject::Destroy_Self() {
    SDL_DestroyTexture(texture);

    for (const auto child : children) {
        child->Destroy_Self();
    }

    delete this;
}