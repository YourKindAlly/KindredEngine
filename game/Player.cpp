#include "Player.h"
#include "../header_files/Sprite.h"
#include "../header_files/GameWindow.h"

Player::Player(GameWindow* window) : Object(window) {
    transform = Transform{ Vector2(300, 200) };

    auto sprite = window->Create_Render_Object<Sprite>("../assets/ship.png");
    sprite->Set_Position(transform.position);
    children.push_back(sprite);
}