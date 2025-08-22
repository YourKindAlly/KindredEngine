#include "../header_files/Rect.h"


Rect::Rect(const float width, const float height) {
    this->width = width;
    this->height = height;

    center = {width/2, height/2};
}

Rect::~Rect() = default;
