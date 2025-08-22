#include <cmath>
#include "../../header_files/Object.h"
#include "../../header_files/GameWindow.h"

Object::Object(GameWindow* window) : game_window(window) { }

void Object::Update(float delta) { }

void Object::Set_Position_In_Viewport(const Vector2 position) {
    transform.position = game_window->Get_Viewport()->Get_Center() + position;
    dest_rect.x = transform.position.x;
    dest_rect.y = transform.position.y;
    Move_Children();
}

Transform* Object::Get_Transform() {
    return &transform;
}

void Object::Set_Position(const Vector2 position) {
    transform.position = position;
    dest_rect.x = transform.position.x;
    dest_rect.y = transform.position.y;
    Move_Children();
}

void Object::Set_Rotation(const float rotation) {
    transform.rotation = rotation;
    Rotate_Children();
}

void Object::Set_Forward(const float rotation) {
    const auto rotation_degrees = rotation * (static_cast<float>(M_PI) / 180.0f);
    transform.forward.x = std::cos(rotation_degrees);
    transform.forward.y = std::sin(rotation_degrees);
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

void Object::Rotate_Children() const {
    for (const auto child : children) {
        child->Set_Rotation(transform.rotation);
        child->Rotate_Children();
    }
}

void Object::Destroy_Self() {
    for (const auto child : children) {
        child->Destroy_Self();
    }

    delete this;
}
