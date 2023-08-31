#include "loadTexture.h"

loadTexture::loadTexture(char *filename)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

    _texture = IMG_LoadTexture(SDL_Render* render, filename);
    
    return _texture;   
}

void blint(SDL_Texture *texture, int x, int y)
{
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    
    SDL_QueryTexture (texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy   (SDL_Render* render, _texture, NULL, &dest);
}