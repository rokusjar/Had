#ifndef CMAP_H_INCLUDED
#define CMAP_H_INCLUDED

#include <SDL.h>
#include <vector>
#include "CTile.h"
/**
    CMap::OnLoad:
        Nacte mapu ze souboru (Generuju pomoci GenerateMap.cpp) a zaplni vector TileList
        Kazdy Tile dostane ID, type a souradnice

    CMap::OnInit:
        Nacita textury mapy

    CMap::OnRender:
        Kresli Tiles na zaklade jejich typu
*/
//---------------------------------------------------------------------------
class CMap {

    private:

        SDL_Window *Window;
        SDL_Renderer *Renderer;

        std::vector<CTile> TileList;

        SDL_Texture *wallTexture;
        SDL_Texture *groundTexture;

    public:

        CMap(SDL_Window *Window, SDL_Renderer *Renderer);
        ~CMap();

    public:

        bool OnLoad(const char *File);

        bool OnInit();

        void OnRender();
};

#endif // CMAP_H_INCLUDED
