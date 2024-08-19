#pragma once

// 一応Actor基底クラスを作っておいた
class Actor
{
public:
    Actor(class Game* game);
    virtual ~Actor() = default;
    
    virtual void processInput();
    virtual void update();
    virtual void draw();

private:
    class Game* mGame;
};

