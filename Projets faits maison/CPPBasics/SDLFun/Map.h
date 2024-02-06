#pragma once
#include "Game.h"

class Map
{
public:
	Map();
	~Map();
	void LoadMap();
	void DrawMap();
private:
	SDL_Rect* srcRect, destRect;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];
};