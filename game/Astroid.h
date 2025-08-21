#ifndef KINDREDENGINE_ASTROID_H
#define KINDREDENGINE_ASTROID_H

#include "../header_files/Object.h"

enum Direction {
    Left,
    Right,
};

class Astroid : public Object {
public:
    explicit Astroid(GameWindow* window);

    void Update(float delta) override;

    Vector2 direction{};
    Direction rotation_direction = Left;
    float move_speed = 10;
};


#endif //KINDREDENGINE_ASTROID_H