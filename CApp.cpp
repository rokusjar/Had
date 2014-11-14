#include "CApp.h"
#include <SDL.h>
//---------------------------------------------------------------------------
CApp::CApp(){

    MainWindow = NULL;
    Renderer = NULL;

    Running = true;
    Map = nullptr;
    Snake = nullptr;
    Fruit = nullptr;
    Score = nullptr;

    //Time
    previousTime = 0;
    currentTime = 0;
    deltaT = new double;
    *deltaT = 0;
    frameTime = 0;

    Delay = 70;
}
//---------------------------------------------------------------------------
int CApp::OnExecute(){

    if(OnInit() == false) {
        return -1;
    }

    SDL_Event Event;

    while(Running) {

        handleFPS();

        //Delay in miliseconds (10 = 100fps)
        if(frameTime >= Delay) {

            while(SDL_PollEvent(&Event)) {

                OnEvent(&Event);
            }

            OnLoop();
            OnRender();

            frameTime = 0;
        }
    }

    OnCleanup();

    return 0;
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {

    CApp theApp;

    return theApp.OnExecute();
}
//---------------------------------------------------------------------------
void CApp::handleFPS(){

    previousTime = currentTime;
    currentTime = SDL_GetTicks();
    *deltaT = (currentTime - previousTime);

    frameTime += *deltaT;

}
//---------------------------------------------------------------------------


