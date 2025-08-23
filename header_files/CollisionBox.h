#ifndef KINDREDENGINE_COLLISIONBOX_H
#define KINDREDENGINE_COLLISIONBOX_H

#include "CollisionObject.h"
#include "Rect.h"

class CollisionBox : public CollisionObject {
public:
    CollisionBox(GameWindow* window, const Rect& shape);

    bool Is_Colliding(CollisionBox& other);

    Rect shape;
    int layer = 0;
    int mask = 0;
};

#endif //KINDREDENGINE_COLLISIONBOX_H