#ifndef SDL3TEST_SPRITE_H
#define SDL3TEST_SPRITE_H

#include "RenderObject.h"

class Sprite : public RenderObject {
public:
    explicit Sprite(GameWindow* window, const std::string& path);
};


#endif //SDL3TEST_SPRITE_H