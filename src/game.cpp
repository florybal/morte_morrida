//
// Created by soonluck8 on 6/23/23.
//
#include "game.h"

game::game()
{

}

game::~game()
{

}

void game::run()
{
    init();

    while(running())
    {
        processEvent();
        update();
        render();
        //n_game-> renderTile(tileWidth, tileHeight, _texture);
    }
    clean();
    
}

void game::clean()
{

    SDL_DestroyRenderer(_render);
    SDL_DestroyWindow(_window);
    SDL_DestroyTexture(_img);
    SDL_Quit();

}

void game::update()
{

}
void game::render()
{
    SDL_RenderClear(_render);
    SDL_SetRenderDrawColor(_render, 96, 128, 150, 100);
    SDL_RenderCopy(_render, _img, NULL, &_rect);
    SDL_RenderPresent(_render);
}

void game::init()
{

    isRuning = true;

    int rendererFlags = SDL_RENDERER_ACCELERATED;
    int windowFlags   = 0;

    _window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               screen_Width, screen_Height, windowFlags);

    if (SDL_Init(SDL_INIT_VIDEO)< 0)
        std::cout<<"nao foi possivel inicializar o SDL: \n" << SDL_GetError();
    

    if(!_window)
        std::cout<<"nao foi possivel criar a janela: \n"
                 << screen_Width, SDL_GetError();

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    _render = SDL_CreateRenderer(_window, -1, rendererFlags);

    if(!_render)
        std::cout<<"nao foi possivel criar renderer : \n" << SDL_GetError();
    
    _img = IMG_LoadTexture(_render, "../assets/cat.png");

    _rect.x = 16;
    _rect.y = 16;
    _rect.w = screen_Width/2  - _rect.x/2;
    _rect.h = screen_Height/2 - _rect.y/2;
    
}   

void game::processEvent()
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                isRuning = false;
                break;

            default:
                break;
        }
    }
}
