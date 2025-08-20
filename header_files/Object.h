#ifndef SDL3TEST_GAMEOBJECT_H
#define SDL3TEST_GAMEOBJECT_H

#include <list>
#include <string>
#include "../header_files/Transform.h"

class GameWindow;

class Object {
public:
    explicit Object(GameWindow* window);
    virtual ~Object() = default;

    virtual void DestroySelf();

    std::string name;
    Transform transform;
    Object* parent = nullptr;
    std::list<Object*> children;
};


#endif //SDL3TEST_GAMEOBJECT_H