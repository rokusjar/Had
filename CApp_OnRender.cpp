#include "CApp.h"
//---------------------------------------------------------------------------
void CApp::OnRender() {

    SDL_RenderClear(Renderer);
    //----------------------------------

    Map->OnRender();
    Snake->OnRender();
    Fruit->OnRender();
    Score->OnRender();

    //----------------------------------
    SDL_RenderPresent(Renderer);
}
