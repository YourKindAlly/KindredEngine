#include "../header_files/Vector2.h"
#include <cmath>


Vector2::Vector2() {
    x = 0;
    y = 0;
}


Vector2::Vector2(const float x, const float y) {
    this->x = x;
    this->y = y;
}

Vector2 Vector2::operator+=(const Vector2& right) const {
    Vector2 temp = *this;
    temp.x += right.x;
    temp.y += right.y;
    return temp;
}

float Vector2::GetMagnitude() const {
    return std::sqrt(x * x + y * y);
}

void Vector2::Normalize() {
    float magnitude = GetMagnitude();

    if (magnitude <= 0)
        return;

    x /= magnitude;
    y /= magnitude;
}