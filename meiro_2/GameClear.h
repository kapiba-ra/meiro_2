#pragma once
#include "Scene.h"

class GameClear :
    public Scene
{
public:
    GameClear(class Game* game);

    //void proc();  // 下の三つを回す
    void processInput() override;
        //void update() override;
        //void draw() override;
    void nextScene();
};

