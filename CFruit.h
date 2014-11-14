#ifndef CFRUIT_H
#define CFRUIT_H

#include <SDL.h>
#include <iostream>

#include "CTile.h"
#include "CMessage.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
//---------------------------------------------------------------------------
class CFruit{

    private:

        SDL_Window *MainWindow;
        SDL_Renderer *Renderer;

        std::vector<SDL_Texture*> FruitTextures;

        unsigned int currentTexture;

    public:

        CTile PreviousFruit;
        CTile CurrentFruit;

        bool Eaten;

        CFruit(SDL_Window *MainWindow, SDL_Renderer *Renderer);
        ~CFruit();

    public:

        bool OnInit();

        void OnLoop();

        void OnRender();

    private:

        void Spawn();
};

#endif // CFRUIT_H
