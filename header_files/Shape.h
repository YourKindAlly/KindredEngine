#ifndef KINDREDENGINE_SHAPE_H
#define KINDREDENGINE_SHAPE_H


class Shape {
public:
    virtual ~Shape() = default;

    virtual bool Is_Intersecting(const Shape& other);
};


#endif //KINDREDENGINE_SHAPE_H