#ifndef KINDREDENGINE_COLLISIONBOX_H
#define KINDREDENGINE_COLLISIONBOX_H

#include "CollisionObject.h"

class CollisionBox : public CollisionObject {
public:
    CollisionBox(GameWindow *window, const Shape &shape);
};

#endif //KINDREDENGINE_COLLISIONBOX_H