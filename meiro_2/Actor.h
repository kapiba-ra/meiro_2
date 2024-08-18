#pragma once

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

