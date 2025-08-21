#ifndef SDL3TEST_VECTOR2_H
#define SDL3TEST_VECTOR2_H


struct Vector2 {
    Vector2();
    Vector2(float x, float y);

    Vector2 operator+=(const Vector2& right) const;
    Vector2 operator+(const Vector2 &right) const;
    Vector2 operator*(float right) const;

    [[nodiscard]] float GetMagnitude() const;
    void Normalize();

    float x = 0;
    float y = 0;
};


#endif //SDL3TEST_VECTOR2_H