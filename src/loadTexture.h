#include "include.h"

class loadTexure
{
public:
    SDL_Texture *loadTexture(char* filename);
    void blint(SDL_Texture* texture, int x, int y);

public:
    SDL_Texture* _texture;
};