#pragma once
#include "Scene.h"

class GameClear :
    public Scene
{
public:
    GameClear(class Game* game);

    //void proc();  // ‰º‚ÌŽO‚Â‚ð‰ñ‚·
    void processInput() override;
        //void update() override;
        //void draw() override;
    void nextScene();
};

