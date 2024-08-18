#pragma once
#include <conio.h>  // for _getch()
#include <windows.h>
#include <iostream>
#include "Game.h"
#include <cstdlib>

class Scene
{
public:
    Scene(class Game* game);
    virtual ~Scene() {};
    
    virtual void init() {};
    virtual void proc();
        virtual void processInput() {};
        virtual void update() {};
        virtual void draw() {};

protected:
    class Game* mGame;
};

