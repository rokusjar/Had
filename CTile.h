#ifndef CTILE_H_INCLUDED
#define CTILE_H_INCLUDED

#include "Define.h"
/**
    Tile reprezentuje jeden dilek grafickeho okna. Celkem zabira plochu 8x8 px (viz Define.h)
    Kazdy Tile ma svoje ID, svuj type a svoje souradnice
        ID ... Cisluje se od jednicky zleva doprava ve stylu [1 2 3
                                                              4 5 6]
               0 je vychozi hodnota

        Type ... urcuje typ a pro prehlednost pouziva enum hodnoty
                 NONE je vychozi hodnota
*/
//---------------------------------------------------------------------------
enum {
    // GROUND = 1
    // WALL   = 2
    TILE_TYPE_NONE = 0,
    TILE_TYPE_GROUND,
    TILE_TYPE_WALL,
    TILE_TYPE_SNAKE,
    TILE_TYPE_FRUIT
};
//---------------------------------------------------------------------------
class CTile {

    public:

        int TileID;
        int TypeID;

        int X;
        int Y;

    public:

        CTile();
        CTile(int X, int Y, int ID, int type);
};

#endif // CTILE_H_INCLUDED
