#include "../header_files/Object.h"

void Object::AddChild(const std::shared_ptr<Object>& object) {
    children.push_back(object);
}