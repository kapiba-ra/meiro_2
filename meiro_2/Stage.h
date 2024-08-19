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
    std::vector<std::string> StageData;         // �e�X�e�[�W�̃f�[�^��ۑ����� Load�p
    std::vector<std::vector<Object>> Objects;   // �X�e�[�W�̏����Ǘ�����
    int currentStage;       // ���݂̃X�e�[�W�̃C���f�b�N�X
    bool Change = false;    // Stage�̐؂�ւ�
    bool GetKey = false;    // ��(k)�̊l��
};

