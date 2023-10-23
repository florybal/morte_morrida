#include "textureManager.h"

textureManager::textureManager()
{

}

textureManager::~textureManager()
{

}

bool textureManager::load(std::string fileName, std::string id, SDL_Renderer* _renderer)
{
	SDL_Surface* _tempSurface = IMG_Load(fileName.c_str());

	if (_tempSurface == 0)
		return false;

	SDL_Texture* _texture = SDL_CreateTextureFromSurface(_renderer, _tempSurface);
	SDL_FreeSurface(_tempSurface);

	if (_tempSurface != 0)
	{
		_textureMap[id] = _texture;
		return true;

	}

	return false;
}

void textureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* _renderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;

	destRect.x = 0;
	destRect.y = 0;

	SDL_RenderCopyEx(_renderer, _textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void textureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* _renderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;

	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(_renderer, _textureMap[id], &srcRect,
		&destRect, 0, 0, flip);
}