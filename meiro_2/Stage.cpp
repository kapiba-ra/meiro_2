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
    // 方向は現状使っていないが,押せる物体の実装等を見越して
    Vector2 Pdir = mGame->player()->GetPdir();
    Vector2 newPpos = curPpos + Pdir;

    // 更新後が壁(#)の位置
    if (Objects[newPpos.y][newPpos.x] == Object::E_Wall)
    {
        return;
    }
    // 更新後が鍵(k)の位置
    else if (Objects[newPpos.y][newPpos.x] == Object::E_Key)
    {
        std::cout << "鍵をかくとくした" << std::endl;
        GetKey = true;
    }
    // 更新後がゴール(G)の位置
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
        coord.Y = i+1;  // 2行目から描画
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
        if (currentStage >= 3)  // クリア時のステージ番号
        {
            mGame->ChangeScene(Game::E_GameClear);
        }
        else
        {
            ChangeStage();  // 次のステージに変更
        }
    }
}

void Stage::LoadStageData(const std::string& filename)
{
    // ファイルの読み込み
    std::ifstream file(filename);
    std::string line;
    StageData.clear();
    while (std::getline(file, line))
    {
        StageData.push_back(line);
    }
    file.close();

    // ステージのデータは注意して用意する必要がある(StageData[0].length())
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
                mGame->player()->SetPpos(Vector2(j, i));    // player位置の設定
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
    // Stage名の表示 現状２桁まで
    std::cout << "Stage_" << std::setw(2) << std::setfill('0') << currentStage << std::endl;
    // ここはtxtファイルをそのまま表示
    for (const auto& line : StageData)
    {
        std::cout << line << std::endl;
    }
}

void Stage::ChangeStage()
{
    currentStage++;     // 次のステージに行って
    init();             // 初期化
}
