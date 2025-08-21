#ifndef SDL3TEST_RENDEROBJECT_H
#define SDL3TEST_RENDEROBJECT_H

#include <SDL3/SDL.h>
#include "../header_files/Object.h"

class RenderObject : public Object {
public:
    explicit RenderObject(GameWindow* window, const std::string& path);

    void Destroy_Self() override;

    int z_order = 0;
    SDL_Texture* texture = nullptr;
protected:
    std::string texture_path;
};

#endif //SDL3TEST_RENDEROBJECT_H