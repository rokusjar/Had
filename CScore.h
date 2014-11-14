#ifndef CSCORE_H_INCLUDED
#define CSCORE_H_INCLUDED

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <sstream>

#include "CMessage.h"
//---------------------------------------------------------------------------
class CScore{

    private:

        SDL_Window *MainWindow;
        SDL_Renderer *Renderer;

        SDL_Texture *scoreTexture;
        TTF_Font *scoreFont;
        SDL_Color fontColor;

        Uint8 R, G, B, A;

        int X, Y;
        int w, h;

        std::string value;
        int scoreValue;

    public:

        CScore(SDL_Window *Window, SDL_Renderer *Renderer);
        ~CScore();

        void rise();

    public:

        bool OnInit();

        void onLoop();

        void OnRender();

};


#endif // CSCORE_H_INCLUDED
