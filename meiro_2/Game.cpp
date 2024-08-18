#include "Game.h"
#include "Title.h"
#include "Stage.h"
#include "GameClear.h"
#include "Player.h"

Game::Game()
	: mIsRunning(true)
{ // Šî–{ƒƒ“ƒo•Ï”‚Ì‰Šú‰»‚¾‚¯‚É‚µ‚Ä‚¨‚­
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
