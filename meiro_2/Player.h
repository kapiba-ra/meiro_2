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
    Vector2 GetPdir() const { return Pdir; }
    void SetPpos(const Vector2& p) { Ppos = p; }

private:
    Vector2 Ppos;       // Player position
    Vector2 Pdir;       // Player direction
    char Input;
};

