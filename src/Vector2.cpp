#include <cmath>
#include <SDL3/SDL.h>
#include "../header_files/Vector2.h"

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

Vector2 Vector2::operator*=(float right) const {
    Vector2 temp = *this;
    temp.x *= right;
    temp.y *= right;
    return temp;
}

Vector2 Vector2::operator+(const Vector2& right) const {
    return {this->x + right.x, this->y + right.y};
}

Vector2 Vector2::operator*(const float right) const {
    return {this->x * right, this->y * right};
}

float Vector2::GetMagnitude() const {
    return std::sqrt(x * x + y * y);
}

void Vector2::Normalize() {
    const float magnitude = GetMagnitude();

    if (magnitude < 0.9 && magnitude > -0.9)
        return;

    x /= magnitude;
    y /= magnitude;
}

Vector2 Vector2::Get_Random_Direction() {
    Vector2 temp{
        static_cast<float>(SDL_rand(30) - 10) * 0.1f,
        static_cast<float>(SDL_rand(30) - 10) * 0.1f
    };

    if (temp.x < 0.9 && temp.x > -0.9 && temp.y < 0.9 && temp.y > -0.9)
        temp.x = 1;

    temp.Normalize();

    return temp;
}