#include "Player.h"
#include <conio.h>
#include <iostream>

Player::Player(Game* game)
	: Actor(game)
	, Input(0)
{
}

void Player::processInput()
{
	Input = _getch();
}

void Player::update()
{
	PposNext = Ppos;
	switch (Input)
	{
	case 'w':	// ��
		PposNext.y -= 1;
		break;
	case 's':	// ��
		PposNext.y += 1;
		break;
	case 'a':	// ��
		PposNext.x -= 1;
		break;
	case 'd':	// �E
		PposNext.x += 1;
		break;
	default :
		break;
	}
}
