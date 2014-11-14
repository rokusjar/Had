#ifndef CSNAKE_H_INCLUDED
#define CSNAKE_H_INCLUDED

#include <SDL.h>
#include <vector>
#include "CTile.h"
#include "CMessage.h"

/**
    CSnake::OnInit:
        Nacita texturu

    CSnake::OnRender:
        Kresli hada
**/
enum Heading{UP = 0,DOWN,LEFT,RIGHT, NONE};
//---------------------------------------------------------------------------
class CSnake{

    private:

        SDL_Window *Window;
        SDL_Renderer *Renderer;
        SDL_Texture *SnakeTexture;

        Heading direction;

        double *deltaT;

    public:

        std::vector<CTile> Tiles;

        CSnake(SDL_Window *Window, SDL_Renderer *Renderer, double *deltaT);
        ~CSnake();

        void grow();

    public:

        bool OnInit();

        void onEvent(SDL_Event *Event);

        void onLoop();

        void OnRender();

    private:

        void Move();

};


#endif // CSNAKE_H_INCLUDED
