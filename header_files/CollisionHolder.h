#ifndef KINDREDENGINE_COLLISIONHOLDER_H
#define KINDREDENGINE_COLLISIONHOLDER_H

#include "Object.h"
#include "CollisionBox.h"

class CollisionHolder : public Object {
public:
    explicit CollisionHolder(GameWindow *window);

    virtual void On_Collision_Enter(const CollisionBox& other);
    virtual void On_Collision_Exit(const CollisionBox& other);

    CollisionBox* colliding_with = nullptr;
};


#endif //KINDREDENGINE_COLLISIONHOLDER_H