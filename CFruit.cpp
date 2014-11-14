#include "CFruit.h"
//---------------------------------------------------------------------------
CFruit::CFruit(SDL_Window *MainWindow, SDL_Renderer *Renderer){

    this->MainWindow = MainWindow;
    this->Renderer = Renderer;

    PreviousFruit = CTile(0,0,0,4);
    CurrentFruit = CTile(0,0,0,4);

    Eaten = true;

    currentTexture = 0;

    srand (time(NULL));
}
//---------------------------------------------------------------------------
CFruit::~CFruit(){

    for(SDL_Texture *tex : FruitTextures){

        SDL_DestroyTexture(tex);
    }

}
//---------------------------------------------------------------------------
bool CFruit::OnInit(){

    SDL_Surface *tempSurface = NULL;
    SDL_Texture *tempTexture = NULL;
    //----------------------------------------------------------------
    if( (tempSurface = SDL_LoadBMP("bitmaps/blueFruit.bmp")) == NULL ){

        CMessage::showformat("CFruit::OnInit - bitmapa nenactena {}",{"blueFruit.bmp"});
        return false;
    }

    tempTexture = SDL_CreateTextureFromSurface(Renderer,tempSurface);
    FruitTextures.push_back(tempTexture);

    if( (tempSurface = SDL_LoadBMP("bitmaps/lightgreenFruit.bmp")) == NULL ){

        CMessage::showformat("CFruit::OnInit - bitmapa nenactena {}",{"lightgreenFruit.bmp"});
        return false;
    }

    tempTexture = SDL_CreateTextureFromSurface(Renderer,tempSurface);
    FruitTextures.push_back(tempTexture);


    if( (tempSurface = SDL_LoadBMP("bitmaps/purpleFruit.bmp")) == NULL ){

        CMessage::showformat("CFruit::OnInit - bitmapa nenactena {}",{"purpleFruit.bmp"});
        return false;
    }

    tempTexture = SDL_CreateTextureFromSurface(Renderer,tempSurface);
    FruitTextures.push_back(tempTexture);

    //----------------------------------------------------------------
    SDL_FreeSurface(tempSurface);

    return true;
}
//---------------------------------------------------------------------------
void CFruit::OnLoop(){

    if(Eaten){

        Spawn();
        Eaten = false;
    }

}
//---------------------------------------------------------------------------
void CFruit::OnRender(){

    SDL_Rect dest = {CurrentFruit.X,CurrentFruit.Y,TILE_SIZE,TILE_SIZE};

    SDL_Texture *tex = FruitTextures[currentTexture];

    SDL_RenderCopy(Renderer,tex,NULL,&dest);

}
//---------------------------------------------------------------------------
void CFruit::Spawn(){

    //random texture
    currentTexture = rand() % 3;

    //random coordinates
    unsigned int X = (rand() %(WWIDTH-3*TILE_SIZE)) + 2*TILE_SIZE;
    X = X - (X % TILE_SIZE);
    unsigned int Y = (rand() %(WHEIGHT-3*TILE_SIZE)) + 2*TILE_SIZE;
    Y = Y - (Y % TILE_SIZE);

    CurrentFruit.X = X;
    CurrentFruit.Y = Y;
}
//---------------------------------------------------------------------------
