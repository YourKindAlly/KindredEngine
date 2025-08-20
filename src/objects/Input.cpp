#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_events.h>
#include "../../header_files/Input.h"

Input::Input(GameWindow* window) : Object(window) { }

void Input::Create_Action(const std::string& action_name, SDL_Keycode key) {
    auto input_action = new InputAction{key, false};
    input_actions.insert({action_name, input_action});
}

bool Input::Is_Action_Down(const std::string& action_name) {
    return input_actions[action_name]->pressed;
}

bool Input::Is_Action_Up(const std::string& action_name) {
    return !input_actions[action_name]->pressed;
}

Vector2 Input::Get_Vector(std::string &pos_x, std::string &neg_x, std::string &pos_y, std::string &neg_y) {
    Vector2 vector{};

    if (Is_Action_Up(pos_x))
        vector.x = 1;
    if (Is_Action_Down(neg_x))
        vector.x = -1;
    if (Is_Action_Down(pos_y))
        vector.y = 1;
    if (Is_Action_Down(neg_y))
        vector.y = -1;

    return vector;
}

Vector2 Input::Get_Normalized_Vector(std::string &pos_x, std::string &neg_x, std::string &pos_y, std::string &neg_y) {
    Vector2 vector{};

    if (Is_Action_Up(pos_x))
        vector.x = 1;
    if (Is_Action_Down(neg_x))
        vector.x = -1;
    if (Is_Action_Down(pos_y))
        vector.y = 1;
    if (Is_Action_Down(neg_y))
        vector.y = -1;

    vector.Normalize();

    return vector;
}


void Input::Update() {
    const bool* keys = SDL_GetKeyboardState(nullptr);
    SDL_PumpEvents();

    for (auto& [key, value] : input_actions) {
        input_actions[key]->pressed = keys[value->key];
    }
}