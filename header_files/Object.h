#ifndef SDL3TEST_GAMEOBJECT_H
#define SDL3TEST_GAMEOBJECT_H

#include <list>
#include <string>
#include <SDL3/SDL.h>
#include "../header_files/Transform.h"

class GameWindow;

class Object {
public:
    explicit Object(GameWindow* window);
    virtual ~Object() = default;

    void Set_Position(Vector2 position);
    virtual void Update(float delta);
    void Move_Children() const;
    virtual void Destroy_Self();

    template<typename T>
    T* Get_First_Child();

    std::string name;
    Transform transform;
    Object* parent = nullptr;
    std::list<Object*> children{};
    SDL_FRect source_rect{0, 0, 64, 64};
    SDL_FRect dest_rect{0, 0, 64, 64};
};


#endif //SDL3TEST_GAMEOBJECT_H