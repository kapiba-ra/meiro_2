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

		E_SceneNums,
	};
	void ChangeScene(SCENE_ID id);

private:
	class Scene* Scenes[E_SceneNums];
	SCENE_ID CurSceneId;


public:
	class Player* player() { return playerObj; }
	void EndGame() { mIsRunning = false; }
private:
	class Player* playerObj;
	bool mIsRunning;
};
