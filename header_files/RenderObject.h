#ifndef SDL3TEST_RENDEROBJECT_H
#define SDL3TEST_RENDEROBJECT_H

#include <SDL3/SDL.h>
#include "../header_files/Object.h"

class GameWindow;

class RenderObject : public Object {
public:
    explicit RenderObject(GameWindow* window, const std::string &path);

    void Set_Position(Vector2 position);
    void DestroySelf() override;

    int z_order = 0;
    SDL_Texture* texture = nullptr;
    SDL_FRect source_rect{0, 0, 64, 64};
    SDL_FRect dest_rect{0, 0, 64, 64};
protected:
    std::string texture_path;
};


#endif //SDL3TEST_RENDEROBJECT_H