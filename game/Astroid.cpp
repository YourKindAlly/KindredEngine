#include "Astroid.h"

#include "../header_files/GameWindow.h"
#include "../header_files/Sprite.h"

Astroid::Astroid(GameWindow* window) : Object(window) {
    direction = Vector2::Get_Random_Direction();

    auto sprite = window->Create_Render_Object<Sprite>("../assets/astroid.png");
    sprite->parent = this;
    children.push_back(sprite);
}

void Astroid::Update(float delta) {
    Set_Position(Get_Transform()->position + direction * move_speed * delta);
}