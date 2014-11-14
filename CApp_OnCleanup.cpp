#include "CApp.h"
//---------------------------------------------------------------------------
void CApp::OnCleanup() {

    SDL_DestroyRenderer(Renderer);
    Renderer = nullptr;

    SDL_DestroyWindow(MainWindow);
    MainWindow = nullptr;

    TTF_Quit();
    SDL_Quit();
}
