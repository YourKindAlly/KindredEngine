#ifndef SDL3TEST_GAMEWINDOW_H
#define SDL3TEST_GAMEWINDOW_H

#include <string>
#include <SDL3/SDL.h>
#include "../header_files/Viewport.h"
#include "../header_files/Object.h"
#include "../header_files/RenderObject.h"

class GameWindow {
public:
    explicit GameWindow(int width, int height);
    ~GameWindow();

    template<typename T>
    T* Create_Object();

    template<typename T>
    T* Create_Render_Object(std::string& path);

    void Start();
    void Frame_Update() const;

    SDL_Renderer* sdl_renderer;
    SDL_ScaleMode scale_mode;
    std::list<Object*> objects{};
    std::list<RenderObject*> render_objects{};
private:
    SDL_Window* sdl_window;
    Viewport viewport;
};


#endif //SDL3TEST_GAMEWINDOW_H
