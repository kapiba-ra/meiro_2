#pragma once
#include "Scene.h"

class GameClear :
    public Scene
{
public:
    GameClear(class Game* game);

    //void proc();  // ���̎O����
    void processInput() override;
        //void update() override;
        //void draw() override;
    void nextScene();
};

