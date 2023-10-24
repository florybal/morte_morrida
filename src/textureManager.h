#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "include.h"
#include <map>

class textureManager
{
public:
	textureManager();
	~textureManager();
public:
	bool load(std::string fileName, std::string id, SDL_Renderer* _renderer);
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* _renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* _renderer, SDL_RendererFlip flip);
public:
	std::map<std::string, SDL_Texture*> _textureMap;
};

#endif

