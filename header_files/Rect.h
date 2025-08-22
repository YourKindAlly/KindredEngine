#ifndef KINDREDENGINE_RECT_H
#define KINDREDENGINE_RECT_H

#include "Shape.h"

class Rect : public Shape {
public:
    Rect(float width, float height);
    ~Rect() override;
    float width = 0;
    float height = 0;
};

#endif //KINDREDENGINE_RECT_H