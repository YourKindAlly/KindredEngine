#include "../header_files/Viewport.h"

Viewport::Viewport(const int width, const int height) {
    this->width = width;
    this->height = height;

    center = Vector2{ static_cast<float>(width / 2), static_cast<float>(height / 2) };
}

Vector2 Viewport::Get_Center() const {
    return center;
}

int Viewport::Get_Width() const {
    return width;
}

int Viewport::Get_Height() const {
    return height;
}