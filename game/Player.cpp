#include "Player.h"
#include "../header_files/Sprite.h"

Player::Player(GameWindow* window) : Object(window) {
    transform = Transform{};

    auto sprite = window->Create_Render_Object<Sprite>("../assets/ship.png");
    children.push_back(sprite);
}