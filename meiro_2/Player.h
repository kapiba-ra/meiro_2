#pragma once
#include "Actor.h"
#include "Vector2.h"

class Player :
    public Actor
{
public:
    Player(class Game* game);

    void processInput()override;
    void update()override;

    Vector2 GetPpos() const { return Ppos; }
    Vector2 GetPposNext() const { return PposNext; }
    void SetPpos(const Vector2& p) { Ppos = p; }
    void SetPposNext(const Vector2& p) { PposNext = p; }

private:
    Vector2 Ppos;
    Vector2 PposNext;
    char Input;
};

