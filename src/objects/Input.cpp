#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_events.h>
#include "../../header_files/Input.h"
#include "../../header_files/GameWindow.h"

Input::Input(GameWindow* window) : Object(window) { }

void Input::Create_Action(const std::string& action_name, SDL_Scancode key) {
    auto input_action = new InputAction{key, false};
    input_actions.insert({action_name, input_action});
}

bool Input::Is_Action_Down(const std::string& action_name) {
    return input_actions[action_name]->pressed;
}

bool Input::Is_Action_Up(const std::string& action_name) {
    return !input_actions[action_name]->pressed;
}

Vector2 Input::Get_Vector(const std::string &pos_x, const std::string &neg_x, const std::string &pos_y, const std::string &neg_y) {
    Vector2 vector{};

    if (Is_Action_Up(pos_x))
        vector.x = 1;
    else if (Is_Action_Down(neg_x))
        vector.x = -1;
    else
        vector.x = 0;

    if (Is_Action_Down(pos_y))
        vector.y = 1;
    else if (Is_Action_Down(neg_y))
        vector.y = -1;
    else
        vector.y = 0;

    return vector;
}

Vector2 Input::Get_Normalized_Vector(const std::string& pos_x, const std::string& neg_x, const std::string& pos_y, const std::string& neg_y) {
    Vector2 vector{};

    if (Is_Action_Down(neg_y))
        vector.x = 1;
    else if (Is_Action_Down(pos_y))
        vector.x = -1;
    else
        vector.x = 0;

    if (Is_Action_Down(neg_x))
        vector.y = 1;
    else if (Is_Action_Down(pos_x))
        vector.y = -1;
    else
        vector.y = 0;

    vector.Normalize();

    return vector;
}


void Input::Update(const float delta) {
    const bool* keys = SDL_GetKeyboardState(nullptr);
    SDL_PumpEvents();

    for (auto& [key, value] : input_actions) {
        value->pressed = keys[value->key];
    }
}