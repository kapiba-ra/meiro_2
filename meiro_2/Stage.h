#pragma once
#include "Scene.h"
#include <vector>
#include <string>

class Stage :
    public Scene
{
public:
    Stage(class Game* game);

    void init() override;
        void processInput() override;
        void update() override;
        void draw() override;
    void nextScene();

    enum class Object : char
    {
        E_Wall,
        E_Space,
        E_Player,
        E_Goal,
        E_Key,
    };

private:
    std::string StageData;
    std::vector< std::vector<Object>> Objects;
    bool Change = false;    // Stage‚ÌØ‚è‘Ö‚¦
    bool GetKey = false;    // Œ®(k)‚ÌŠl“¾
};

