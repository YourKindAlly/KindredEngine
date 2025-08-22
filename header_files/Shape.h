#ifndef KINDREDENGINE_SHAPE_H
#define KINDREDENGINE_SHAPE_H

#include "Vector2.h"

class Shape {
public:
    virtual ~Shape() = default;

    virtual bool Is_Intersecting(const Shape& other);
protected:
    Vector2 center;
};


#endif //KINDREDENGINE_SHAPE_H