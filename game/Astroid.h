#ifndef KINDREDENGINE_ASTROID_H
#define KINDREDENGINE_ASTROID_H

#include "../header_files/Object.h"
#include "../header_files/CollisionHolder.h"

enum Direction {
    Left = -1,
    Right = 1,
};

class Astroid : public CollisionHolder {
public:
    explicit Astroid(GameWindow* window);

    void Update(float delta) override;

    CollisionBox* collision;
    Vector2 direction{};
    Direction rotation_direction = Left;
    float rotation_speed = 10;
    float move_speed = 10;
};


#endif //KINDREDENGINE_ASTROID_H