#pragma once

//2次元ベクトルの配列と、ベクトル同士の計算のための定義(演算子のオーバーロード)
//必要最低限のものだけ用意しています。

class Vector2 {
public:
    int x, y;
    Vector2(int x = 0, int y = 0);
    Vector2 operator+ (const Vector2& v) const;
    Vector2 operator- (const Vector2& v) const;
    Vector2 operator* (int f) const;
    void operator+= (const Vector2& v);
    void operator*= (int f);
};

int length(const Vector2& a);
int sqLength(const Vector2& a);
Vector2 normalize(const Vector2& a);