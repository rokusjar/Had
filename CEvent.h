#ifndef CEVENT_H_INCLUDED
#define CEVENT_H_INCLUDED

#include <SDL.h>
//---------------------------------------------------------------------------

class CEvent {

    public:

        CEvent();

        virtual ~CEvent();

        virtual void OnEvent(SDL_Event* Event);

    public:

        virtual void OnKeyDown(SDL_Scancode sym);

        virtual void OnExit();

};

#endif // CEVENT_H_INCLUDED
