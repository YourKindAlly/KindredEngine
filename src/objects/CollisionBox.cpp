#include "../../header_files/CollisionBox.h"
#include "../../header_files/Rect.h"

CollisionBox::CollisionBox(GameWindow* window, const Shape& shape) : CollisionObject(window, shape){
    this->shape = shape;
}

bool CollisionBox::Is_Colliding(CollisionObject& other) {
    if (dynamic_cast<Rect*>(&shape) == nullptr) return false;
    return
        Get_Transform()->position.x + dynamic_cast<Rect*>(&shape)->width <= other.Get_Transform()->position.x ||
        other.Get_Transform()->position.x + dynamic_cast<Rect*>(&other.shape)->width <= Get_Transform()->position.x ||
        Get_Transform()->position.y + dynamic_cast<Rect*>(&shape)->height <= other.Get_Transform()->position.y ||
        other.Get_Transform()->position.y  + dynamic_cast<Rect*>(&other.shape)->height <= Get_Transform()->position.y;
}
