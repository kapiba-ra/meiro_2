#include "Game.h"
#include "Title.h"
#include "Stage.h"
#include "GameClear.h"
#include "Player.h"

Game::Game()
	: mIsRunning(true)
{ // ��{�����o�ϐ��̏����������ɂ��Ă���
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

	// �V�[����Title�Ȃ�Space�L�[�������Ƃ���Stage��
	// �V�[����Stage�Ȃ�Actor�N���X��ProcessInput()���Ăяo��(���O�ς��Ă���������)
	// Stage�ł�WASD��������p�̈ړ�����px,py���ύX�����
	// ��{�I�ɂ�Actor��update���Ăяo���������ȁB�Ȃ̂ňȉ������̒��g�̓��e�ł�
	// p��pos(struct�Ŏ����Ă�����)��dx,dy�Ɋ�Â��čX�V����B
	// �X�V���player�̈ʒu�ɂ����playerstate���Ǘ�����
	// ����Wall�Ȃ�X�V���Ȃ��B����Goal�Ȃ�player��pos���X�V����B
	// ����space�Ȃ�player��pos���X�V����B
	// �ړ����state�ɂ���ĕς���
	// Goal : �ړ���̏ꏊ��p��\���AScene��Clear�ɑJ�ڂ�����B
	// Space : �ړ���̏ꏊ��p��\��
