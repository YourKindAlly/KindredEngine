#include "Player.h"
#include "../header_files/Sprite.h"
#include "../header_files/GameWindow.h"

Player::Player(GameWindow* window) : Object(window) {
    transform = Transform{ Vector2(300, 200) };

    auto sprite = window->Create_Render_Object<Sprite>("../assets/ship.png");
    sprite->parent = this;
    sprite->Set_Position(transform.position);
    children.push_back(sprite);

    auto input = window->Create_Object<Input>();
    input->parent = this;
    children.push_back(input);

    this->input = input;
}

void Player::Update() {
    input->Create_Action("move_up", SDLK_W);
    input->Create_Action("move_down", SDLK_S);
    input->Create_Action("move_left", SDLK_A);
    input->Create_Action("move_right", SDLK_D);
}