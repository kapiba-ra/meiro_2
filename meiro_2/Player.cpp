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
	case 'w':	// è„
		PposNext.y -= 1;
		break;
	case 's':	// â∫
		PposNext.y += 1;
		break;
	case 'a':	// ç∂
		PposNext.x -= 1;
		break;
	case 'd':	// âE
		PposNext.x += 1;
		break;
	default :
		break;
	}
}
