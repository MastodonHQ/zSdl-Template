#ifndef _GRAPHICS_HXX_
#define _GRAPHICS_HXX_
#include "SDL2/SDL.h"
#include <iostream>
#include <string>

class gfxManager
{
private:
     SDL_Renderer * rnd;
     SDL_Window * win;

     std::string wndName;
public:
    SDL_Event event;
    SDL_Rect pos;
    gfxManager(std::string winName) : wndName(winName)
    {
        pos.x = 0;
        pos.y = 0;
    }
    ~gfxManager()
    {
        SDL_DestroyRenderer(rnd);
        SDL_DestroyWindow(win);
    }

     SDL_Texture * drawImage(std::string imagePath);
     void applyTexture(SDL_Texture * t, int x, int y);
     SDL_Renderer * getRenderer() { return rnd; }
     SDL_Event getEvent() { return event; }
     int init();
};

SDL_Texture * gfxManager::drawImage(std::string imagePath)
{
    SDL_Surface *loadedImage = nullptr;
        SDL_Texture *texture = nullptr;

        loadedImage = SDL_LoadBMP(imagePath.c_str());
    if (loadedImage != nullptr)
    {
        texture = SDL_CreateTextureFromSurface(rnd, loadedImage);
        SDL_FreeSurface(loadedImage);
    }
    else
    {
        std::cout << SDL_GetError() << std::endl;

    }
        return texture;
}

void gfxManager::applyTexture(SDL_Texture * t, int x, int y)
{

    if(pos.x >= 0 && pos.y >= 0)
    {
        pos.x = x;
        pos.y = y;
    }
    else if (x < 0 && y < 0)
    {
        pos.x = 0;
        pos.y = 0;
    }
    else
    {
        pos.x = x;
        pos.y = y;
    }

    SDL_QueryTexture(t, NULL, NULL, &pos.w, &pos.h);

    SDL_RenderCopy(rnd, t, NULL, &pos);
}

int gfxManager::init()
{
        win = SDL_CreateWindow(wndName.c_str(),100,100, 1280, 600, SDL_WINDOW_SHOWN);
        if(win == nullptr)
        {
            std::cout << "Window Creation Failed" << std::endl;
            std::cout << SDL_GetError() << std::endl;
            return 1222;
        }

        rnd = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if(rnd == nullptr)
        {
            std::cout << "Renderer Creation Failed" << std::endl;
            std::cout << SDL_GetError() << std::endl;
            return 1333;
        }
        return 0;
}
#endif // _GRAPHICS_HXX_
