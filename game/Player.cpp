#include "Player.h"
#include "../header_files/Sprite.h"
#include "../header_files/GameWindow.h"

Player::Player(GameWindow* window) : Object(window) {
    transform = Transform{ Vector2(300, 200) };

    auto sprite = window->Create_Render_Object<Sprite>("../assets/ship.png");
    sprite->parent = this;
    sprite->Set_Position(transform.position);
    children.push_back(sprite);

    const auto input_object = window->Create_Object<Input>();
    input_object->parent = this;
    children.push_back(input_object);

    this->input = input_object;

    input->Create_Action("move_up", SDL_SCANCODE_W);
    input->Create_Action("move_down", SDL_SCANCODE_S);
    input->Create_Action("move_left", SDL_SCANCODE_A);
    input->Create_Action("move_right", SDL_SCANCODE_D);
}

void Player::Update(const float delta) {
    const auto move_direction = input->Get_Normalized_Vector("move_left", "move_right", "move_up", "move_down");
    Set_Position(transform.position + move_direction * move_speed * delta);
    Move_Children();
}