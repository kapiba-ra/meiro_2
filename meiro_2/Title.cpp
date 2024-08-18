#include "Title.h"

Title::Title(Game* game)
	: Scene(game)
{
}

void Title::processInput()
{
	std::cout << "ーーーーーーー[めいろ]ーーーーーーー" << std::endl;
	std::cout << "移動方法 : W (↑), A (←), S (↓),D (→) " << std::endl;
	std::cout << "'#'：壁" << std::endl;
	std::cout << "'p'：プレイヤー" << std::endl;
	std::cout << "'k'：カギ" << std::endl;
	std::cout << "'G'：ゴール" << std::endl;
	std::cout << "				何かキーを押してスタート" << std::endl;
	_getch();
	nextScene();
}

//void Title::update()
//{
//	std::cout << "Titleのupdate" << std::endl;
//}
//
//void Title::draw()
//{
//	std::cout << "Titleのdraw" << std::endl;
//	nextScene();
//}

void Title::nextScene()
{
	mGame->ChangeScene(Game::E_Stage);
}
