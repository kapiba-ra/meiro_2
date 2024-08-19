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

    void LoadStageData(const std::string& filename);
    void ChangeStage();

private:
    std::vector<std::string> StageData;         // 各ステージのデータを保存する Load用
    std::vector<std::vector<Object>> Objects;   // ステージの情報を管理する
    int currentStage;       // 現在のステージのインデックス
    bool Change = false;    // Stageの切り替え
    bool GetKey = false;    // 鍵(k)の獲得
};

