#include "GameClear.h"

GameClear::GameClear(Game* game)
	: Scene(game)
{
}

void GameClear::processInput()
{
	// 本当は別の場所でコンストラクタで表示させたいかも
	std::cout << "GameClear!! 'q'で終了" << std::endl;
	char input = 'a';	// 初期化 aに意味はない
	while (input != 'q')
	{
		input = _getch();
	}
	mGame->EndGame();
}

//void GameClear::update()
//{
//	std::cout << "GameClearのupdate" << std::endl;
//}
//
//void GameClear::draw()
//{
//	std::cout << "GameClearのdraw" << std::endl;
//}

void GameClear::nextScene()
{
	mGame->ChangeScene(Game::E_Title);
}
