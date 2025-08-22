#ifndef SDL3TEST_VIEWPORT_H
#define SDL3TEST_VIEWPORT_H

#include "Vector2.h"

class Viewport {
public:
    Viewport(int width, int height);
    [[nodiscard]] int Get_Width() const;
    [[nodiscard]] int Get_Height() const;
    [[nodiscard]] Vector2 Get_Center() const;
private:
    int width = 0;
    int height = 0;
    Vector2 center;
};

#endif //SDL3TEST_VIEWPORT_H