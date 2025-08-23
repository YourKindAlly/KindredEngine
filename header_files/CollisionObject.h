#ifndef KINDREDENGINE_COLLISIONOBJECT_H
#define KINDREDENGINE_COLLISIONOBJECT_H

#include "Object.h"

class GameWindow;

class CollisionObject : public Object {
public:
    explicit CollisionObject(GameWindow* window);
    ~CollisionObject() override;
};


#endif //KINDREDENGINE_COLLISIONOBJECT_H