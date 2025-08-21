#ifndef KINDREDENGINE_COLLISIONSHAPE_H
#define KINDREDENGINE_COLLISIONSHAPE_H

#include "Shape.h"
#include "Object.h"

class GameWindow;

class CollisionObject : public Object {
public:
    Shape shape{};
protected:
    explicit CollisionObject(GameWindow* window, const Shape& shape);
    ~CollisionObject();
};


#endif //KINDREDENGINE_COLLISIONSHAPE_H