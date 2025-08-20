#include "../header_files/Object.h"

Object::Object(GameWindow* window) { }

void Object::Update() { }

void Object::Destroy_Self() {
    for (const auto child : children) {
        child->Destroy_Self();
    }

    delete this;
}

template<typename T>
T* Object::Get_First_Child() {
    static_assert(std::is_base_of_v<Object, T>, "T must derive from Object");
    for (const auto child : children) {
       if (dynamic_cast<T*>(child) != nullptr)
           return child;
    }

    return nullptr;
}