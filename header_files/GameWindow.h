#ifndef SDL3TEST_GAMEWINDOW_H
#define SDL3TEST_GAMEWINDOW_H

#include <string>
#include <SDL3/SDL.h>
#include <vector>
#include "Viewport.h"
#include "Object.h"
#include "RenderObject.h"
#include "CollisionBox.h"
#include "Rect.h"

class GameWindow {
public:
    explicit GameWindow(int width, int height);
    ~GameWindow();

    template<typename T>
    T* Create_Object();

    template<typename T>
    T* Create_Render_Object(const std::string& path);

    template<typename T>
    T* Create_Collision_Object(const Rect& shape);

    Viewport* Get_Viewport();

    void Start();
    void Frame_Update(float delta) const;

    SDL_Renderer* sdl_renderer;
    SDL_ScaleMode scale_mode;
    std::vector<Object*> objects{};
    std::vector<RenderObject*> render_objects{};
    std::vector<CollisionBox*> collision_objects{};
private:
    SDL_Window* sdl_window;
    Viewport viewport;
};


#endif //SDL3TEST_GAMEWINDOW_H
