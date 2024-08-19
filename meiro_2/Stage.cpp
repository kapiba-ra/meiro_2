#include "Stage.h"
#include "Player.h"
#include <iomanip> 
#include <fstream>
#include <sstream>

Stage::Stage(Game* game)
	: Scene(game)
    , currentStage(1)
{
}

void Stage::init()
{
    Change = false;
    GetKey = false;
    LoadStageData("stage_" + std::to_string(currentStage) + ".txt");
}

void Stage::processInput()
{
	mGame->player()->processInput();
}

void Stage::update()
{
    mGame->player()->update();

    Vector2 curPpos = mGame->player()->GetPpos();
    // �����͌���g���Ă��Ȃ���,�����镨�̂̎����������z����
    Vector2 Pdir = mGame->player()->GetPdir();
    Vector2 newPpos = curPpos + Pdir;

    // �X�V�オ��(#)�̈ʒu
    if (Objects[newPpos.y][newPpos.x] == Object::E_Wall)
    {
        return;
    }
    // �X�V�オ��(k)�̈ʒu
    else if (Objects[newPpos.y][newPpos.x] == Object::E_Key)
    {
        std::cout << "���������Ƃ�����" << std::endl;
        GetKey = true;
    }
    // �X�V�オ�S�[��(G)�̈ʒu
    else if (Objects[newPpos.y][newPpos.x] == Object::E_Goal)
    {
        // ���̗L���ɂ���ĕς�鏈��
        if (GetKey == false)
        {
            std::cout << "���������Ă��Ȃ�" << std::endl;
            return;
        }
        else if (GetKey == true)
        {
            Change = true;
        }
    }

    /* -------------------- �ʒu���̍X�V�͍Ō�ɍs�� -------------------- */
    // Objects
    Objects[curPpos.y][curPpos.x] = Object::E_Space;
    Objects[newPpos.y][newPpos.x] = Object::E_Player;
    // Ppos
    mGame->player()->SetPpos(newPpos);
}

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void Stage::draw()
{
    COORD coord = { 0, 0 };

    for (int i = 0; i < Objects.size(); i++)
    {
        coord.Y = i+1;  // 2�s�ڂ���`��
        for (int j = 0; j < Objects[i].size(); j++)
        {
            coord.X = j;
            SetConsoleCursorPosition(hConsole, coord);

            switch (Objects[i][j])
            {
            case Object::E_Wall:
                std::cout << '#';
                break;
            case Object::E_Space:
                std::cout << ' ';
                break;
            case Object::E_Player:
                std::cout << 'p';
                break;
            case Object::E_Goal:
                std::cout << 'G';
                break;
            case Object::E_Key:
                std::cout << 'k';
                break;
            default:
                std::cout << ' ';
                break;
            }
        }
        std::cout << '\n';
    }
	nextScene();
}

void Stage::nextScene()
{
    if (Change)
    {
        if (currentStage >= 3)  // �N���A���̃X�e�[�W�ԍ�
        {
            mGame->ChangeScene(Game::E_GameClear);
        }
        else
        {
            ChangeStage();  // ���̃X�e�[�W�ɕύX
        }
    }
}

void Stage::LoadStageData(const std::string& filename)
{
    // �t�@�C���̓ǂݍ���
    std::ifstream file(filename);
    std::string line;
    StageData.clear();
    while (std::getline(file, line))
    {
        StageData.push_back(line);
    }
    file.close();

    // �X�e�[�W�̃f�[�^�͒��ӂ��ėp�ӂ���K�v������(StageData[0].length())
    int StageH = StageData.size();
    int StageW = static_cast<int>(StageData[0].length());

    Objects = std::vector<std::vector<Object>>(StageH, std::vector<Object>(StageW));

    for (int i = 0; i < StageH; ++i)
    {
        for (int j = 0; j < StageW; ++j)
        {
            switch (StageData[i][j])
            {
            case '#':
                Objects[i][j] = Object::E_Wall;
                break;
            case ' ':
                Objects[i][j] = Object::E_Space;
                break;
            case 'p':
                Objects[i][j] = Object::E_Player;
                mGame->player()->SetPpos(Vector2(j, i));    // player�ʒu�̐ݒ�
                break;
            case 'G':
                Objects[i][j] = Object::E_Goal;
                break;
            case 'k':
                Objects[i][j] = Object::E_Key;
                break;
            default:
                Objects[i][j] = Object::E_Space;
                break;
            }
        }
    }

    system("cls");
    // Stage���̕\�� ����Q���܂�
    std::cout << "Stage_" << std::setw(2) << std::setfill('0') << currentStage << std::endl;
    // ������txt�t�@�C�������̂܂ܕ\��
    for (const auto& line : StageData)
    {
        std::cout << line << std::endl;
    }
}

void Stage::ChangeStage()
{
    currentStage++;     // ���̃X�e�[�W�ɍs����
    init();             // ������
}
