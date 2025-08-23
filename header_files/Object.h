#ifndef SDL3TEST_GAMEOBJECT_H
#define SDL3TEST_GAMEOBJECT_H

#include <list>
#include <string>
#include <SDL3/SDL.h>
#include "Transform.h"

class GameWindow;

class Object {
public:
    explicit Object(GameWindow* window);
    virtual ~Object() = default;

    Transform* Get_Transform();
    void Set_Position(Vector2 position);
    void Set_Rotation(float rotation);
    void Set_Forward(float rotation);
    virtual void Update(float delta);
    virtual void Destroy_Self();

    template<typename T>
    T* Get_First_Child();

    std::string name;
    Object* parent = nullptr;
    std::list<Object*> children{};
    SDL_FRect source_rect{0, 0, 64, 64};
    SDL_FRect dest_rect{0, 0, 64, 64};
    Vector2 center{ dest_rect.w/2, dest_rect.h/2 };
protected:
    void Set_Position_In_Viewport(Vector2 position);
    GameWindow* game_window;
private:
    void Move_Children() const;
    void Rotate_Children() const;
    Transform transform{};
};


#endif //SDL3TEST_GAMEOBJECT_H