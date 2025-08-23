#include "Astroid.h"
#include "../header_files/GameWindow.h"
#include "../header_files/Sprite.h"
#include "../header_files/Rect.h"
#include "../header_files/CollisionBox.h"

Astroid::Astroid(GameWindow* window) : CollisionHolder(window) {
    direction = Vector2::Get_Random_Direction();

    const auto sprite = window->Create_Render_Object<Sprite>("../assets/astroid.png");
    sprite->parent = this;
    children.push_back(sprite);

    const Rect collision_shape{ 44, 44 };
    auto collision_box = window->Create_Collision_Object<CollisionBox>(collision_shape);
    collision = collision_box;
    collision->layer = 1;
    collision->parent = this;
    children.push_back(collision);

    rotation_direction = SDL_rand(2) == 0 ? Left : Right;
}

void Astroid::Update(float delta) {
    Set_Position(Get_Transform()->position + direction * move_speed * delta);
    Set_Rotation(Get_Transform()->rotation + static_cast<float>(rotation_direction) * rotation_speed * delta);
}