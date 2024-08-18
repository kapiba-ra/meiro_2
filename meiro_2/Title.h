#pragma once
#include "Scene.h"

class Title :
    public Scene
{
public:
    Title(class Game* game);

    void processInput() override;
    //void update() override;
    //void draw() override;
    void nextScene();
};

