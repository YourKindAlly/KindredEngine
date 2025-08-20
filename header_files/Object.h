#ifndef SDL3TEST_GAMEOBJECT_H
#define SDL3TEST_GAMEOBJECT_H

#include <memory>
#include <list>
#include <string>
#include "../header_files/Transform.h"

class Object {
public:
    Object() = default;
    virtual ~Object() = default;

    void AddChild(const std::shared_ptr<Object>& object);

    std::string name;
    Transform transform;
    std::shared_ptr<Object> parent = nullptr;
    std::list<std::shared_ptr<Object>> children;
};


#endif //SDL3TEST_GAMEOBJECT_H