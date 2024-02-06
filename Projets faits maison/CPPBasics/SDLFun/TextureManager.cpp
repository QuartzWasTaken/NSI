#include "TextureManager.h"
#include "Game.h"

SDL_Texture* TextureManager::LoadTexture(const char* texName)
{
	SDL_Surface* tmpSurf = IMG_Load(texName);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurf);
	SDL_FreeSurface(tmpSurf);

	return tex;
}