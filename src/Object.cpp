#include "../header_files/Object.h"
#include "../header_files/GameWindow.h"

Object::Object(GameWindow* window) { }

void Object::DestroySelf() {
    for (const auto child : children) {
        child->DestroySelf();
    }

    delete this;
}