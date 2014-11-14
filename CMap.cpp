#include "CMap.h"
#include "CMessage.h"
#include <stdio.h>
#include <sstream>
//---------------------------------------------------------------------------
CMap::CMap(SDL_Window *Window, SDL_Renderer *Renderer) {

    this->Window = Window;
    this->Renderer = Renderer;
    this->wallTexture = NULL;
    this->groundTexture = NULL;
}
//---------------------------------------------------------------------------
CMap::~CMap(){

    SDL_DestroyTexture(wallTexture);
    SDL_DestroyTexture(groundTexture);

}
//---------------------------------------------------------------------------
bool CMap::OnLoad(const char *File){

    FILE *pMapFile;
    pMapFile = fopen(File,"r");

    if( pMapFile == NULL ){
        CMessage::show("CMap::OnLoad: Nepodarilo se otevrit soubor mapy.");
        return false;
    }

    //Pocet dlazdic v okne
    unsigned int Xcount = WWIDTH/TILE_SIZE;
    unsigned int Ycount = WHEIGHT/TILE_SIZE;

    int ID = 1;
    //Souradnice dlazdic
    int X = 0;
    int Y = 0;

    for(unsigned int Yax = 0; Yax < Ycount; Yax++){

        for(unsigned int Xax = 0; Xax < Xcount; Xax++){

            CTile tempTile;

            fscanf(pMapFile,"%d",&tempTile.TypeID);
            tempTile.TileID = ID;

            tempTile.X = X;
            tempTile.Y = Y;

            TileList.push_back(tempTile);

            ID++;
            X += TILE_SIZE;
        }
        X = 0;
        Y += TILE_SIZE;
    }

    if(TileList.size() != (Xcount*Ycount)){
       CMessage::show("CMap::OnLoad: Soubor mapy byl spatne precten - neodpovida pocet dlazdic");
       return false;
    }

    fclose(pMapFile);

    return true;
}
//---------------------------------------------------------------------------
bool CMap::OnInit(){

    SDL_Surface *tempSurfWall = NULL;
    SDL_Surface *tempSurfGround = NULL;

    if( (tempSurfWall = SDL_LoadBMP("bitmaps/wall.bmp")) == NULL){

        CMessage::showformat("CMapp::OnRender - bitmapa nenactena {}",{"wall.bmp"});
        return false;
    }
    if( (tempSurfGround = SDL_LoadBMP("bitmaps/ground.bmp")) == NULL){

        CMessage::showformat("CMapp::OnRender - bitmapa nenactena {}",{"ground.bmp"});
        return false;
    }

    wallTexture = SDL_CreateTextureFromSurface(Renderer,tempSurfWall);
    groundTexture = SDL_CreateTextureFromSurface(Renderer,tempSurfGround);

    SDL_FreeSurface(tempSurfWall);
    SDL_FreeSurface(tempSurfGround);

    return true;
}
//---------------------------------------------------------------------------
void CMap::OnRender(){

    SDL_Rect dest = {0,0,TILE_SIZE,TILE_SIZE};

    for(CTile Tile : TileList) {

        SDL_Texture *tempTexture = NULL;

        if(Tile.TypeID == TILE_TYPE_GROUND){
            tempTexture = groundTexture;
        }

        if(Tile.TypeID == TILE_TYPE_WALL){
            tempTexture = wallTexture;
        }

        dest.x = Tile.X;
        dest.y = Tile.Y;

        SDL_RenderCopy(Renderer,tempTexture,NULL,&dest);
    }
}
//---------------------------------------------------------------------------
