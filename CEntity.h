#ifndef CENTITY_H_INCLUDED
#define CENTITY_H_INCLUDED

#include <SDL.h>
#include <vector>
#include "CTile.h"

/**

**/

//---------------------------------------------------------------------------
class CEntity{

    private:

        std::vector<CTile> Tiles;

        SDL_Texture *EntityTexture;

    public:

};



#endif // CENTITY_H_INCLUDED
