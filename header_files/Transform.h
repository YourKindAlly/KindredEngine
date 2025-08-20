#ifndef SDL3TEST_TRANSFORM_H
#define SDL3TEST_TRANSFORM_H

#include "Vector2.h"

class Transform {
public:
    Vector2 position = Vector2{0, 0};
    float rotation = 0;
};


#endif //SDL3TEST_TRANSFORM_H