#include <SDL.h>
#include "Game.h"
#include <iostream>
#undef main

Game* game = nullptr;

int main()
{
	const int FPS = 144;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();

	game->init("henlo", 50, 50, 640, 640, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;
		std::cout << frameTime << std::endl;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->clean();
}