#include "Scene.h"

Scene::Scene(Game* game)
{
	mGame = game;
}

void Scene::proc()
{
	processInput();
	update();
	draw();
}
