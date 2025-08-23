#include <iostream>
#include <memory>
#include "../header_files/GameWindow.h"
#include "../header_files/RootObject.h"
#include "../header_files/RenderObject.h"
#include "../header_files/Sprite.h"
#include "../game/Player.h"
#include "../header_files/Input.h"
#include "../header_files/CollisionObject.h"
#include "../header_files/CollisionBox.h"

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

template<class T>
T* GameWindow::Create_Object() {
    static_assert(std::is_base_of_v<Object, T>, "T must derive from Object");
    auto object = new T{ this };
    objects.push_back(object);
    return object;
}

template<class T>
T* GameWindow::Create_Render_Object(const std::string& path) {
    static_assert(std::is_base_of_v<RenderObject, T>, "T must derive from RenderObject");
    auto object = new T{ this, path };

    if (!object->texture) {
        std::cerr << "Creating texture failed: " << SDL_GetError() << '\n';
    }

    SDL_SetTextureScaleMode(object->texture, scale_mode);
    objects.push_back(object);
    render_objects.push_back(object);
    return object;
}

template<class T>
T* GameWindow::Create_Collision_Object(const Rect& shape) {
    static_assert(std::is_base_of_v<CollisionBox, T>, "T must derive from CollisionObject");
    auto object = new T{ this, shape };

    objects.push_back(object);
    collision_objects.push_back(object);
    return object;
}

void GameWindow::Start() {
    const auto root = Create_Object<RootObject>();
    objects.push_back(root);
}

void GameWindow::Frame_Update(float delta) const {
    SDL_RenderClear(sdl_renderer);

    for (const auto object : objects) {
        object->Update(delta);
    }

    for (auto mask_object : collision_objects) {
        for (auto layer_object : collision_objects) {
            if (mask_object == layer_object) continue;
            if (mask_object->mask != layer_object->layer) continue;
            if (dynamic_cast<CollisionHolder*>(layer_object->parent) == nullptr) continue;

            if (const auto parent = dynamic_cast<CollisionHolder*>(layer_object->parent); parent->colliding_with == nullptr) {
                if (!mask_object->Is_Colliding(*layer_object)) continue;
                parent->colliding_with = mask_object;
                parent->On_Collision_Enter(*mask_object);
            }
            else if (parent->colliding_with != nullptr && parent->colliding_with == mask_object) {
                if (mask_object->Is_Colliding(*layer_object)) continue;
                parent->colliding_with = nullptr;
                parent->On_Collision_Exit(*mask_object);
            }
        }
    }

    std::list<std::unique_ptr<SDL_FPoint>> centers{};

    for (auto& object : render_objects) {
        auto center = std::make_unique<SDL_FPoint>(SDL_FPoint{object->center.x, object->center.y});
        centers.push_back(std::move(center));
        SDL_RenderTextureRotated(
            sdl_renderer,
            object->texture,
            &object->source_rect,
            &object->dest_rect,
            object->Get_Transform()->rotation,
            center.get(),
            SDL_FLIP_NONE
            );
    }

    SDL_RenderPresent(sdl_renderer);
}

Viewport* GameWindow::Get_Viewport() {
    return &viewport;
}

GameWindow::~GameWindow() {
    SDL_DestroyRenderer(sdl_renderer);
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}

template Player* GameWindow::Create_Object<Player>();
template Input* GameWindow::Create_Object<Input>();
template Sprite* GameWindow::Create_Render_Object<Sprite>(const std::string& path);