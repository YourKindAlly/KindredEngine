#ifndef KINDREDENGINE_SHAPE_H
#define KINDREDENGINE_SHAPE_H

#include "Vector2.h"

class Shape {
public:
    virtual ~Shape() = default;
protected:
    Vector2 center;
};


#endif //KINDREDENGINE_SHAPE_H