#include "../../header_files/CollisionObject.h"
#include "../../header_files/GameWindow.h"

CollisionObject::CollisionObject(GameWindow* window, const Shape& shape) : Object(window) {
    this->shape = shape;
}

CollisionObject::~CollisionObject() { }

