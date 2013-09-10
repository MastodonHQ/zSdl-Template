#include "SDL2/SDL.h"
#include "graphics.hxx"
#include "font.hxx"
#include "player.hxx"
#include <sstream>
#include <iostream>



int main (int argc, char * argv[])
{
     if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        std::cout << SDL_GetError()<< std::endl;
        std::cin.get();
        return 1;
    }
    if (TTF_Init() == -1){
    std::cout << TTF_GetError() << std::endl;
    return 2;
    }
    const std::string sans= "C:/Users/Josh/Documents/Just/Code/zSDL-Template/Resources/SourceSansPro-Black.ttf";
    player tPlayer("Test Player", 20 , 20);
    entity pEntity("Background", 0, 0);
    font hp_label(sans, "Hp Label", 0, 0);
    font hp_labelV(sans, "Hp Label Value", 37, 0);
    SDL_Texture * tex;
    SDL_Texture * hp_tex;
    SDL_Texture * hp_tval;
    SDL_Color red;
    red.r = 255;
    red.g = 0;
    red.b = 0;
    SDL_Color black;
    black.r = 0;
    black.g = 0;
    black.b = 0;
    bool quit = false;
    gfxManager gfx = gfxManager("gfxManager Test");
    gfx.init();
    tex = gfx.drawImage("C:/Users/Josh/Documents/Just/Code/zSDL-Template/Resources/mybmp.bmp");
    if(SDL_RenderClear(gfx.getRenderer()) == -1)
    {
        std::cout << "Clearing the Render Buffer Resulted in Error" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        return 1444;
    }
    hp_tex = hp_label.DrawText("HP:", red, 20, gfx.getRenderer());

    SDL_RenderPresent(gfx.getRenderer());
    while(!quit)
    {
    hp_tval = hp_labelV.DrawText(hp_labelV.numToString(tPlayer.getHP()),red,20, gfx.getRenderer());
    if(tPlayer.getHP() <= 0){
                    tPlayer.setHP(100);
                  }
                  else if(tPlayer.getHP() >= 1)
                  {
                   tPlayer.setHP(tPlayer.getHP() - 1);
                  }
        while(SDL_PollEvent(&gfx.event))
              {

                  if(gfx.event.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                    if(gfx.event.type == SDL_KEYDOWN)
                    {
                        switch (gfx.event.key.keysym.sym){
                                case SDLK_s:
                                    pEntity.setLocation(pEntity.getX(),pEntity.getY()+5);
                                    break;
                                case SDLK_w:
                                    pEntity.setLocation(pEntity.getX(),pEntity.getY()-5);
                                    break;
                                case SDLK_a:
                                    pEntity.setLocation(pEntity.getX()-5,pEntity.getY());
                                    break;
                                case SDLK_d:
                                    pEntity.setLocation(pEntity.getX()+5,pEntity.getY());
                                    break;
                        }

                    }

              }
        SDL_RenderClear(gfx.getRenderer());
        gfx.applyTexture(tex, pEntity.getX(), pEntity.getY());
        gfx.applyTexture(hp_tex, hp_label.getX(), hp_label.getY());
        gfx.applyTexture(hp_tval, hp_labelV.getX(), hp_labelV.getY());
        SDL_RenderPresent(gfx.getRenderer());
    }
    SDL_DestroyTexture(tex);
    SDL_Quit();
    return 0;
}
