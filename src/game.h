//
// Created by soonluck8 on 6/23/23.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "include.h"
#include "textureManager.h"


class game {
public:
  game();
  ~game();
  void run();

private:
    void processEvent();
    void update();
    void render();
    void init();
    void clean();

    bool running(){return isRuning;}
private:
    int screen_Width  = 640;
    int screen_Height = 480;

    int m_currentFrame;
    textureManager m_textureManager;

    bool isRuning;

    SDL_Window*   _window  = nullptr;
    SDL_Renderer* _render  = nullptr;
    SDL_Texture*  _img     = nullptr; 
    SDL_Texture*  _texture = nullptr;
    SDL_Rect     _rect;
};


#endif //GAME_GAME_H
