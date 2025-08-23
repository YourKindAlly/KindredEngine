#include "../../header_files/CollisionBox.h"
#include "../../header_files/Rect.h"

CollisionBox::CollisionBox(GameWindow* window, const Rect& shape) : CollisionObject(window), shape(shape) {
}

bool CollisionBox::Is_Colliding(CollisionBox& other) {
    return
        Get_Transform()->position.x + shape.width <= other.Get_Transform()->position.x ||
        other.Get_Transform()->position.x + other.shape.width <= Get_Transform()->position.x ||
        Get_Transform()->position.y + shape.height <= other.Get_Transform()->position.y ||
        other.Get_Transform()->position.y  + other.shape.height <= Get_Transform()->position.y;
}
