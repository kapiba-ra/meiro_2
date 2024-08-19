#include "GameClear.h"

GameClear::GameClear(Game* game)
	: Scene(game)
{
}

void GameClear::processInput()
{
	std::cout << "GameClear!! 'q'�ŏI��" << std::endl;
	char input = 'a';	// ������ a�ɈӖ��͂Ȃ�
	while (input != 'q')
	{
		input = _getch();
	}
	mGame->EndGame();
}

//void GameClear::update()
//{
//	std::cout << "GameClear��update" << std::endl;
//}
//
//void GameClear::draw()
//{
//	std::cout << "GameClear��draw" << std::endl;
//}

void GameClear::nextScene()
{
	mGame->ChangeScene(Game::E_Title);
}
