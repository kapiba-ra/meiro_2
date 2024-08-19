#pragma once
#include "Scene.h"

class Game
{
public:
	Game();
	~Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	enum SCENE_ID
	{
		E_Title,
		E_Stage,
		E_GameClear,
		// 現状ゲームオーバーはない,障害物ができたら追加も視野

		E_SceneNums,
	};
	void ChangeScene(SCENE_ID id);	// 各シーンから呼び出す

private:
	class Scene* Scenes[E_SceneNums];
	SCENE_ID CurSceneId;

// 追加的
public:
	class Player* player() { return playerObj; }
	void EndGame() { mIsRunning = false; }
private:
	class Player* playerObj;	// playerはGameクラスでnewする
	bool mIsRunning;	// RunLoopはこれがtrueなら回る
};
