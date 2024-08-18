#include "Title.h"

Title::Title(Game* game)
	: Scene(game)
{
}

void Title::processInput()
{
	std::cout << "�[�[�[�[�[�[�[[�߂���]�[�[�[�[�[�[�[" << std::endl;
	std::cout << "�ړ����@ : W (��), A (��), S (��),D (��) " << std::endl;
	std::cout << "'#'�F��" << std::endl;
	std::cout << "'p'�F�v���C���[" << std::endl;
	std::cout << "'k'�F�J�M" << std::endl;
	std::cout << "'G'�F�S�[��" << std::endl;
	std::cout << "				�����L�[�������ăX�^�[�g" << std::endl;
	_getch();
	nextScene();
}

//void Title::update()
//{
//	std::cout << "Title��update" << std::endl;
//}
//
//void Title::draw()
//{
//	std::cout << "Title��draw" << std::endl;
//	nextScene();
//}

void Title::nextScene()
{
	mGame->ChangeScene(Game::E_Stage);
}
