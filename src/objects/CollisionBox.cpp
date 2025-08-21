#include "../../header_files/CollisionBox.h"

CollisionBox::CollisionBox(GameWindow* window, const Shape& shape) : CollisionObject(window, shape){
    this->shape = shape;
}