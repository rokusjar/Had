#include "CApp.h"

//---------------------------------------------------------------------------
bool CApp::OnInit() {

    //Basic Initialization
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    //------------------------------------------------------
    //MainWindow
    MainWindow = SDL_CreateWindow("My Game Window",
                                   SDL_WINDOWPOS_CENTERED,
                                   SDL_WINDOWPOS_CENTERED,
                                   WWIDTH, WHEIGHT,
                                   SDL_WINDOW_SHOWN
                                   );
    if (MainWindow == NULL){
        return false;
    }
    //------------------------------------------------------
    //Renderer
    if( (Renderer = SDL_CreateRenderer(MainWindow, -1, 0)) == NULL){
        return false;
    }
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
    SDL_RenderClear(Renderer);

    //------------------------------------------------------
    //Map
    Map = new CMap(MainWindow,Renderer);

    if(Map->OnInit() == false){
        CMessage::show("CMap - inicializace selhala");
        return false;
    }

    std::string mapFilePath = "maps/mainMap.map";
    const char *filepath = mapFilePath.c_str();

    Map->OnLoad(filepath);
    //------------------------------------------------------
    //Snake

    Snake = new CSnake(MainWindow,Renderer,deltaT);

    if (Snake->OnInit() == false){
        CMessage::show("CSnake - inicializace selhala");
        return false;
    }

    //------------------------------------------------------
    //Fruit
    Fruit = new CFruit(MainWindow,Renderer);

    if (Fruit->OnInit() == false){
        CMessage::show("CFruit - inicializace selhala");
        return false;
    }
    //------------------------------------------------------
    //Score
    Score = new CScore(MainWindow,Renderer);

    if( (Score->OnInit()) == false ){
        CMessage::show("CScore - inicializace selhala");
        return false;
    }

    return true;
}






