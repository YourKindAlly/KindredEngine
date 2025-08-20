#ifndef SDL3TEST_RENDEROBJECT_H
#define SDL3TEST_RENDEROBJECT_H

#include "../header_files/Object.h"
#include "../header_files/GameWindow.h"

class RenderObject : public Object {
public:
    explicit RenderObject(GameWindow* window, std::string path);

    void DestroySelf() override;

    int z_order = 0;
    SDL_Texture* texture = nullptr;
protected:
    std::string texture_path;
};


#endif //SDL3TEST_RENDEROBJECT_H