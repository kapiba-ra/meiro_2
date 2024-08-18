#include "Vector2.h"
#include <cmath>

Vector2::Vector2(int x, int y) : x(x), y(y) {}

Vector2 Vector2::operator+ (const Vector2& v) const {
    return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator- (const Vector2& v) const {
    return Vector2(x - v.x, y - v.y);
}

Vector2 Vector2::operator* (int f) const {
    return Vector2(x * f, y * f);
}

void Vector2::operator+= (const Vector2& v) {
    x += v.x;
    y += v.y;
}

void Vector2::operator*= (int f) {
    x *= f;
    y *= f;
}

int length(const Vector2& a) {
    return std::sqrt(a.x * a.x + a.y * a.y);
}

int sqLength(const Vector2& a) {
    return a.x * a.x + a.y * a.y;
}

Vector2 normalize(const Vector2& a) {
    int len = length(a);
    if (len != 0.0f) {
        return Vector2(a.x / len, a.y / len);
    }
    return Vector2(0, 0);
}