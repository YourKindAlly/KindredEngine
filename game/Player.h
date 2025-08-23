#ifndef SDL3TEST_PLAYER_H
#define SDL3TEST_PLAYER_H

#include "../header_files/Object.h"
#include "../header_files/Input.h"
#include "../header_files/CollisionBox.h"
#include "../header_files/CollisionHolder.h"

class Player final : public CollisionHolder {
public:
    explicit Player(GameWindow* window);

    void On_Collision_Enter(const CollisionBox& other) override;
    void On_Collision_Exit(const CollisionBox& other) override;
    void Update(float delta) override;

    Input* input = nullptr;
    CollisionBox* collision = nullptr;

    float move_speed = 100;
    float rotation_speed = 125;
};


#endif //SDL3TEST_PLAYER_H