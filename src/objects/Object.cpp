#include "../../header_files/Object.h"
#include "../../header_files/GameWindow.h"

Object::Object(GameWindow* window) { }

void Object::Update(float delta) { }

void Object::Set_Position(const Vector2 position) {
    transform.position = position;
    dest_rect.x = position.x;
    dest_rect.y = position.y;
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

void Object::Move_Children() const {
    for (const auto child : children) {
        child->Set_Position(transform.position);
        child->Move_Children();
    }
}

void Object::Destroy_Self() {
    for (const auto child : children) {
        child->Destroy_Self();
    }

    delete this;
}
