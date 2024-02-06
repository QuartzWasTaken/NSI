#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texSheet, int x, int y)
{
	xPos = x;
	yPos = y;
	renderer = Game::renderer;
	objTexture = TextureManager::LoadTexture(texSheet);
}

void GameObject::Update()
{
	xPos++;
	yPos++;
	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h * 2;
	destRect.w = srcRect.w * 2;
	destRect.x = xPos;
	destRect.y = yPos;
}

void GameObject::Render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}