#ifndef _FONT_HXX_
#define _FONT_HXX_
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include <stdexcept>
#include <string>
#include <sstream>
#include <iostream>
#include "entity.hxx"

class font : public entity
{
private:
    TTF_Font * mfont;
    int fontSize;
public:
    font(std::string fontFile, std::string id, int fx, int fy) : entity(id, fx, fy)
    {
        fontSize = 20;
        mfont = TTF_OpenFont(fontFile.c_str(), fontSize);
        if(mfont == nullptr)
        {
            throw std::runtime_error("Failed to load font: " + fontFile + TTF_GetError());
        }

    }

    ~font()
    {
        TTF_CloseFont(mfont);
    }

    SDL_Texture * DrawText(std::string message, SDL_Color color, int fontSize, SDL_Renderer * rnd);
    std::string numToString(int n);
};

SDL_Texture * font::DrawText(std::string message, SDL_Color color, int FontSize, SDL_Renderer * rnd)
{
    SDL_Surface * surf = TTF_RenderText_Blended(mfont, message.c_str(), color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(rnd,surf);
    SDL_FreeSurface(surf);
    return texture;
}

std::string font::numToString(int n)
{
    std::string tmp;
    std::ostringstream convert;
    convert << n;
    tmp = convert.str();
    return tmp;
}


#endif //_FONT_HXX_
