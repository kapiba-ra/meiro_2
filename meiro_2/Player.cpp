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
	Pdir = (0, 0);
	switch (Input)
	{
	case 'w':	// è„
		Pdir.y = -1;
		break;
	case 's':	// â∫
		Pdir.y = 1;
		break;
	case 'a':	// ç∂
		Pdir.x = -1;
		break;
	case 'd':	// âE
		Pdir.x = 1;
		break;
	default :
		break;
	}
}
