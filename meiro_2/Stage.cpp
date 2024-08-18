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

    // 四角形のみに対応...
    unsigned __int64 StageH = std::count(StageData.begin(), StageData.end(), '\n');
    int StageW = static_cast<int>(StageData.find('\n'));
    
	Objects ={ StageH, std::vector<Object>(StageW)};

    // Objectsの登録
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
                mGame->player()->SetPpos(Vector2(w, h));    // player位置の設定
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

    // 更新後が壁の位置
    if (Objects[newPpos.y][newPpos.x] == Object::E_Wall)
    {
        return;     //updateしない
    }
    // 更新後が鍵(k)の位置
    else if (Objects[newPpos.y][newPpos.x] == Object::E_Key)
    {
        std::cout << "鍵をかくとくした" << std::endl;
        GetKey = true;
    }
    // 更新後がゴールの位置
    else if (Objects[newPpos.y][newPpos.x] == Object::E_Goal)
    {
        // 鍵の有無によって変わる処理
        if (GetKey == false)
        {
            std::cout << "鍵をもっていない" << std::endl;
            return;
        }
        else if (GetKey == true)
        {
            Change = true;
        }
    }

    /* -------------------- 位置情報の更新は最後に行う -------------------- */
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
        coord.Y = i+1;  // Stage_01等の表示を先頭にするため＋１
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
