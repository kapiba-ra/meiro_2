#include <iostream>
#include <vector>
#include "Game.h"

int main()
{
	Game game;
	bool success = game.Initialize();
	if (success)
	{
		game.RunLoop();
	}
	game.Shutdown();
	return 0;
}
// ここは Game ProgrammingC++ に則った