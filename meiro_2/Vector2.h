#pragma once

//2�����x�N�g���̔z��ƁA�x�N�g�����m�̌v�Z�̂��߂̒�`(���Z�q�̃I�[�o�[���[�h)
//�K�v�Œ���̂��̂����p�ӂ��Ă��܂��B

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