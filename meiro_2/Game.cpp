#include "Game.h"
#include "Title.h"
#include "Stage.h"
#include "GameClear.h"
#include "Player.h"

Game::Game()
	: mIsRunning(true)
{ // 基本メンバ変数の初期化だけにしておく
}

Game::~Game()
{
}

bool Game::Initialize()
{
	Scenes[E_Title] = new Title(this);
	Scenes[E_Stage] = new Stage(this);
	Scenes[E_GameClear] = new GameClear(this);

	playerObj = new Player(this);

	CurSceneId = E_Title;
	return true;
}

void Game::RunLoop()
{
	while (mIsRunning)
	{
		Scenes[CurSceneId]->proc();
	}
}

void Game::Shutdown()
{
	for (int i = 0; i < E_SceneNums; ++i)
	{
		delete Scenes[i];
	}
}

void Game::ChangeScene(SCENE_ID id)
{
	CurSceneId = id;
	Scenes[CurSceneId]->init();
}

	// シーンがTitleならSpaceキーを押すとからStageへ
	// シーンがStageならActorクラスのProcessInput()を呼び出す(名前変えてもいいかも)
	// StageではWASDを押すとpの移動方向px,pyが変更される
	// 基本的にはActorのupdateを呼び出すだけかな。なので以下もその中身の内容です
	// pのpos(structで持っておこう)をdx,dyに基づいて更新する。
	// 更新後のplayerの位置によってplayerstateを管理する
	// もしWallなら更新しない。もしGoalならplayerのposを更新する。
	// もしspaceならplayerのposを更新する。
	// 移動先のstateによって変える
	// Goal : 移動後の場所にpを表示、SceneをClearに遷移させる。
	// Space : 移動後の場所にpを表示
