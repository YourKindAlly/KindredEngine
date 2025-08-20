#ifndef SDL3TEST_APP_H
#define SDL3TEST_APP_H

#include "GameWindow.h"

class Engine {
public:
    Engine();
    void Run() const;

    GameWindow game_window;
};


#endif //SDL3TEST_APP_H