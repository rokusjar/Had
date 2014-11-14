#include "CScore.h"
//---------------------------------------------------------------------------
CScore::CScore(SDL_Window *Window, SDL_Renderer *Renderer){

    this->MainWindow = Window;
    this->Renderer = Renderer;
    scoreTexture = NULL;

    w = 0;
    h = 0;

    X = 24;
    Y = 24;

    R = G = B = A = 255;

    fontColor = {R,G,B,A};

    scoreValue = 0;
    value = "0";

}
//---------------------------------------------------------------------------
bool CScore::OnInit(){

    if( TTF_Init() < 0){
        CMessage::show("TTF se neinicializovalo");
        return false;
    }

    if( (scoreFont = TTF_OpenFont("font/GoldenEye.ttf",60)) == NULL ){
        CMessage::show("Font nenacten");
        return false;
    }

    return true;
}
//---------------------------------------------------------------------------
CScore::~CScore(){

    SDL_DestroyTexture(scoreTexture);

}
//---------------------------------------------------------------------------
void CScore::onLoop(){

}
//---------------------------------------------------------------------------
void CScore::OnRender(){

    fontColor = {R,G,B,A};

    const char *charvalue = value.c_str();

    SDL_Surface *scoreSurface = TTF_RenderText_Solid(scoreFont,charvalue,fontColor);
    scoreTexture = SDL_CreateTextureFromSurface(Renderer,scoreSurface);

    SDL_FreeSurface(scoreSurface);
    scoreSurface = nullptr;

    SDL_QueryTexture(scoreTexture,NULL,NULL,&w,&h);
    SDL_Rect scoreRect = {X,Y,w,h};

    SDL_RenderCopy(Renderer,scoreTexture,NULL,&scoreRect);

}
//---------------------------------------------------------------------------
void CScore::rise(){

    scoreValue += 10;

    std::stringstream sconvert;
    sconvert << scoreValue;
    value = sconvert.str();

}
//---------------------------------------------------------------------------
