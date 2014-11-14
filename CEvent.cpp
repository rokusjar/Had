#include "CEvent.h"
//---------------------------------------------------------------------------
CEvent::CEvent() {

}
//---------------------------------------------------------------------------
CEvent::~CEvent() {

}
//---------------------------------------------------------------------------
void CEvent::OnEvent(SDL_Event* Event) {

    switch(Event->type) {

        case SDL_QUIT: {
            OnExit();
            break;
        }

        case SDL_KEYDOWN: {
            OnKeyDown(Event->key.keysym.scancode);
            break;
        }

        default: {
            break;
        }
    }
}
//---------------------------------------------------------------------------
void CEvent::OnKeyDown(SDL_Scancode sym){
    // pure virtual
}
//---------------------------------------------------------------------------
void CEvent::OnKeyUp(SDL_Scancode sym){
    // pure virtual
}
//---------------------------------------------------------------------------
void CEvent::OnExit(){
    // pure virtual
}
//---------------------------------------------------------------------------
