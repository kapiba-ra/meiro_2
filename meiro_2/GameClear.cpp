#include "GameClear.h"

GameClear::GameClear(Game* game)
	: Scene(game)
{
}

void GameClear::processInput()
{
	std::cout << "GameClear!! 'q'‚ÅI—¹" << std::endl;
	char input = 'a';	// ‰Šú‰» a‚ÉˆÓ–¡‚Í‚È‚¢
	while (input != 'q')
	{
		input = _getch();
	}
	mGame->EndGame();
}

//void GameClear::update()
//{
//	std::cout << "GameClear‚Ìupdate" << std::endl;
//}
//
//void GameClear::draw()
//{
//	std::cout << "GameClear‚Ìdraw" << std::endl;
//}

void GameClear::nextScene()
{
	mGame->ChangeScene(Game::E_Title);
}
