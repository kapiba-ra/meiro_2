#include "Stage.h"
#include "Player.h"
#include <iomanip> 

Stage::Stage(Game* game)
	: Scene(game)
{
}

void Stage::init()
{
	StageData ="\
##########\n\
#p   #   #\n\
#  #   # #\n\
# ###### #\n\
#  G#k   #\n\
##########\n";
	mGame->player()->SetPpos(Vector2(1,1));

    // �l�p�`�݂̂ɑΉ�...
    unsigned __int64 StageH = std::count(StageData.begin(), StageData.end(), '\n');
    int StageW = static_cast<int>(StageData.find('\n'));
    
	Objects ={ StageH, std::vector<Object>(StageW)};

    // Objects�̓o�^
    int h = 0;
    int w = 0;
    for (char c : StageData)
    {
        if (c == '\n')
        {
            h++;
            w = 0;
        }
        else if (h < StageH && w < StageW)
        {
            switch (c)
            {
            case '#':
                Objects[h][w] = Object::E_Wall;
                break;
            case ' ':
                Objects[h][w] = Object::E_Space;
                break;
            case 'p':
                Objects[h][w] = Object::E_Player;
                mGame->player()->SetPpos(Vector2(w, h));    // player�ʒu�̐ݒ�
                break;
            case 'G':
                Objects[h][w] = Object::E_Goal;
                break;
            case 'k':
                Objects[h][w] = Object::E_Key;
                break;
            default:
                Objects[h][w] = Object::E_Space;
                break;
            }
            w++;
        }
    }
    system("cls");
    std::cout << "Stage_01" << std::endl;
    std::cout << StageData << std::endl;
}

void Stage::processInput()
{
	mGame->player()->processInput();
}

void Stage::update()
{
    mGame->player()->update();

    Vector2 curPpos = mGame->player()->GetPpos();
    Vector2 newPpos = mGame->player()->GetPposNext();

    // �X�V�オ�ǂ̈ʒu
    if (Objects[newPpos.y][newPpos.x] == Object::E_Wall)
    {
        return;     //update���Ȃ�
    }
    // �X�V�オ��(k)�̈ʒu
    else if (Objects[newPpos.y][newPpos.x] == Object::E_Key)
    {
        std::cout << "���������Ƃ�����" << std::endl;
        GetKey = true;
    }
    // �X�V�オ�S�[���̈ʒu
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
        coord.Y = i+1;  // Stage_01���̕\����擪�ɂ��邽�߁{�P
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
	    mGame->ChangeScene(Game::E_GameClear);
    }
}
