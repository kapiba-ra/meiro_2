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
		// ����Q�[���I�[�o�[�͂Ȃ�,��Q�����ł�����ǉ�������

		E_SceneNums,
	};
	void ChangeScene(SCENE_ID id);	// �e�V�[������Ăяo��

private:
	class Scene* Scenes[E_SceneNums];
	SCENE_ID CurSceneId;

// �ǉ��I
public:
	class Player* player() { return playerObj; }
	void EndGame() { mIsRunning = false; }
private:
	class Player* playerObj;	// player��Game�N���X��new����
	bool mIsRunning;	// RunLoop�͂��ꂪtrue�Ȃ���
};
