#ifndef KINDREDENGINE_INPUT_H
#define KINDREDENGINE_INPUT_H

#include <map>
#include <SDL3/SDL_keycode.h>

#include "Object.h"

class InputAction {
public:
    SDL_Keycode key;
    bool pressed;
};

class Input : public Object {
public:
    explicit Input(GameWindow* window);

    void Create_Action(const std::string& action_name, SDL_Keycode key);
    bool Is_Action_Down(const std::string& action_name);
    bool Is_Action_Up(const std::string& action_name);
    Vector2 Get_Vector(std::string& pos_x, std::string& neg_x, std::string& pos_y, std::string& neg_y);
    Vector2 Get_Normalized_Vector(std::string& pos_x, std::string& neg_x, std::string& pos_y, std::string& neg_y);
    void Update() override;

    std::map<std::string, InputAction*> input_actions;
};


#endif //KINDREDENGINE_INPUT_H