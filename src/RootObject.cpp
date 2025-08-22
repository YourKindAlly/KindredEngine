#include "../header_files/RootObject.h"
#include "../header_files/GameWindow.h"
#include "../game/Player.h"
#include "../game/Astroid.h"

RootObject::RootObject(GameWindow* window) : Object(window) {
    const auto player = window->Create_Object<Player>();
    player->parent = this;
    children.push_back(player);
    window->objects.push_back(player);

    for (int i = 0; i < 3; i++) {
        const auto astroid = new Astroid{window};
        astroid->parent = this;
        children.push_back(astroid);
        const Vector2 random_position{
            static_cast<float>(SDL_rand(window->Get_Viewport()->Get_Width() - 10)),
            static_cast<float>(SDL_rand(window->Get_Viewport()->Get_Height() - 10))
        };
        window->objects.push_back(astroid);
        astroid->Set_Position(random_position);
    }
}