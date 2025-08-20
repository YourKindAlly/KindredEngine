#include "Player.h"
#include "../header_files/Sprite.h"
#include "../header_files/GameWindow.h"
#include "../header_files/Input.h"

Player::Player(GameWindow* window) : Object(window) {
    transform = Transform{ Vector2(300, 200) };

    const auto sprite = window->Create_Render_Object<Sprite>("../assets/ship.png");
    sprite->parent = this;
    sprite->Set_Position(transform.position);
    children.push_back(sprite);

    const auto input = window->Create_Object<Input>();
    input->parent = this;
    children.push_back(input);
}

void Player::Update() {

}