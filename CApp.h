#ifndef CAPP_H_INCLUDED
#define CAPP_H_INCLUDED

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

#include "Define.h"
#include "CMessage.h"
#include "CMap.h"
#include "CSnake.h"
#include "CFruit.h"
#include "CScore.h"

#include <string>
//---------------------------------------------------------------------------

class CApp{

    //Data members
    private:

        bool Running;

        SDL_Window *MainWindow;

        SDL_Renderer *Renderer;

        CMap *Map;

        CSnake *Snake;

        CFruit *Fruit;

        CScore *Score;

    // Time
    private:

        double previousTime;
        double currentTime;
        double *deltaT;

        double frameTime;
        int Delay;

        void handleFPS();

    // Methods
    public:

        CApp();

        int OnExecute();

    public:

        bool OnInit();

        void OnEvent(SDL_Event* Event);

        void OnLoop();

        void OnRender();

        void OnCleanup();

    public:

        void OnExit();

};

#endif // CAPP_H_INCLUDED
