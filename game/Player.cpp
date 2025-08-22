#include "Player.h"
#include "../header_files/Sprite.h"
#include "../header_files/GameWindow.h"

Player::Player(GameWindow* window) : Object(window) {
    const auto sprite = game_window->Create_Render_Object<Sprite>("../assets/ship.png");
    sprite->parent = this;
    children.push_back(sprite);

    const auto input_object = game_window->Create_Object<Input>();
    input_object->parent = this;
    children.push_back(input_object);

    this->input = input_object;

    input->Create_Action("move_up", SDL_SCANCODE_W);
    input->Create_Action("move_down", SDL_SCANCODE_S);
    input->Create_Action("move_left", SDL_SCANCODE_A);
    input->Create_Action("move_right", SDL_SCANCODE_D);

    Set_Position_In_Viewport({0, 0});
}

void Player::Update(const float delta) {
    const auto forward_direction = input->Get_Axis("move_up", "move_down");
    Set_Position({
            Get_Transform()->position.x + Get_Transform()->forward.x * forward_direction * move_speed * delta,
            Get_Transform()->position.y + Get_Transform()->forward.y * forward_direction * move_speed * delta
    });

    const auto rotation = -input->Get_Axis("move_left", "move_right") * rotation_speed * delta;
    Set_Rotation(Get_Transform()->rotation + rotation);
    Set_Forward(Get_Transform()->rotation);
}