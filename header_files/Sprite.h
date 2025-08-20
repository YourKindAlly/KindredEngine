#ifndef SDL3TEST_SPRITE_H
#define SDL3TEST_SPRITE_H

#include "../header_files/RenderObject.h"

class Sprite final : public RenderObject {
public:
    explicit Sprite(const char* path);
    int z_order = 0;
};


#endif //SDL3TEST_SPRITE_H