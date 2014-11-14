#include "CApp.h"
//---------------------------------------------------------------------------
void CApp::OnLoop() {

    Snake->onLoop();
    Fruit->OnLoop();
    Score->onLoop();

    // Colision
    CTile snakeFront = Snake->Tiles[0];
    CTile fruit = Fruit->CurrentFruit;

    if(snakeFront.X + TILE_SIZE >= fruit.X &&
       snakeFront.X + TILE_SIZE <= fruit.X + TILE_SIZE &&
       snakeFront.Y + TILE_SIZE >= fruit.Y &&
       snakeFront.Y + TILE_SIZE <= fruit.Y + TILE_SIZE
       )
    {
        Fruit->Eaten = true;
        Snake->grow();
        Score->rise();
    }
}
