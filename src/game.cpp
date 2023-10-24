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
    }
    clean();
    
}

void game::clean()
{

    SDL_DestroyRenderer(_render);
    SDL_DestroyWindow(_window);
    //SDL_DestroyTexture(_img);
    SDL_Quit();

}

void game::update()
{

    m_currentFrame = int((( SDL_GetTicks() / 100) % 6 ));

}
void game::render()
{
    SDL_RenderClear(_render);

    m_textureManager.draw("personagem", 0, 0, 168, 216, _render);

    m_textureManager.drawFrame("personagem", 0, 0, 168, 216, 1, m_currentFrame, _render, SDL_FLIP_HORIZONTAL);

    SDL_SetRenderDrawColor(_render, 96, 128, 150, 100);
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
    
    m_textureManager.load("../assets/personagem_56x72.png", "personagem", _render);
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
