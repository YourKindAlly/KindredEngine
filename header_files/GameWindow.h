#ifndef SDL3TEST_GAMEWINDOW_H
#define SDL3TEST_GAMEWINDOW_H

#include <list>
#include <SDL3/SDL.h>
#include "../header_files/Viewport.h"
#include "../header_files/Object.h"

class GameWindow {
public:
    explicit GameWindow(int width, int height);
    ~GameWindow();

    template<class T>
    T *Create_Object();

    void Start();
    void Frame_Update() const;

    SDL_Renderer* sdl_renderer;
    SDL_ScaleMode scale_mode;
private:
    SDL_Window* sdl_window;
    Viewport viewport;
    std::list<std::shared_ptr<Object>> objects;
};


#endif //SDL3TEST_GAMEWINDOW_H