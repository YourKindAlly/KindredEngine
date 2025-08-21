#ifndef SDL3TEST_PLAYER_H
#define SDL3TEST_PLAYER_H

#include "../header_files/Object.h"
#include "../header_files/Input.h"

class Player final : public Object {
public:
    explicit Player(GameWindow* window);

    void Update() override;

    Input* input = nullptr;
};


#endif //SDL3TEST_PLAYER_H