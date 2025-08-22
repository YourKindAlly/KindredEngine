#ifndef KINDREDENGINE_INPUT_H
#define KINDREDENGINE_INPUT_H

#include <map>
#include "Object.h"

class InputAction {
public:
    SDL_Scancode key;
    bool pressed;
};

class Input final : public Object {
public:
    explicit Input(GameWindow* window);

    void Create_Action(const std::string& action_name, SDL_Scancode key);
    bool Is_Action_Down(const std::string& action_name);
    bool Is_Action_Up(const std::string& action_name);
    Vector2 Get_Vector(const std::string& pos_x, const std::string& neg_x, const std::string& pos_y, const std::string& neg_y);
    float Get_Axis(const std::string& pos, const std::string& neg);
    Vector2 Get_Normalized_Vector(const std::string& pos_x, const std::string& neg_x, const std::string& pos_y, const std::string& neg_y);
    void Update(float delta) override;
private:
    std::map<std::string, InputAction*> input_actions;
};

#endif //KINDREDENGINE_INPUT_H