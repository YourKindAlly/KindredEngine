#ifndef SDL3TEST_PLAYER_H
#define SDL3TEST_PLAYER_H

#include "../header_files/Object.h"
#include "../header_files/Input.h"

class Player final : public Object {
public:
    explicit Player(GameWindow* window);

    void Update(float delta) override;

    Input* input = nullptr;
    float move_speed = 0;
};


#endif //SDL3TEST_PLAYER_H