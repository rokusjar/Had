#include "CSnake.h"
//---------------------------------------------------------------------------
CSnake::CSnake(SDL_Window *Window, SDL_Renderer *Renderer, double *deltaT){

    this->Window = Window;
    this->Renderer = Renderer;
    SnakeTexture = NULL;

    this->deltaT = deltaT;

    // starting direction
    direction = RIGHT;

    // snake is born with the body of "Tilesize" tiles
    int X = WWIDTH/4;
    int Y = WHEIGHT/2;

    for(unsigned int I = 0; I < 10; I++){

        CTile tempTile(X,Y,0,3);
        Tiles.push_back(tempTile);

        X -= TILE_SIZE;
    }
}
//---------------------------------------------------------------------------
CSnake::~CSnake(){

    SDL_DestroyTexture(SnakeTexture);
}
//---------------------------------------------------------------------------
bool CSnake::OnInit(){

    SDL_Surface *tempSurf = NULL;

    if( (tempSurf = SDL_LoadBMP("bitmaps/snake.bmp")) == NULL ){

        CMessage::showformat("CMapp::OnRender - bitmapa nenactena {}",{"wall.bmp"});
        return false;
    }
    SnakeTexture = SDL_CreateTextureFromSurface(Renderer,tempSurf);
    SDL_FreeSurface(tempSurf);

    return true;
}
//---------------------------------------------------------------------------
void CSnake::onEvent(SDL_Event *Event){

    switch(Event->key.keysym.sym){

        case SDLK_UP:
            if(direction == DOWN)
                break;

            if(direction != UP)
                direction = UP;

            break;

        case SDLK_DOWN:
            if(direction == UP)
                break;

            if(direction != DOWN)
                direction = DOWN;

            break;

        case SDLK_RIGHT:
            if(direction == LEFT)
                break;

            if(direction != RIGHT)
                direction = RIGHT;

            break;

        case SDLK_LEFT:
            if(direction == RIGHT)
                break;

            if(direction != LEFT)
                direction = LEFT;

            break;

        default:
            break;
    }
}
//---------------------------------------------------------------------------
void CSnake::onLoop(){

    CTile Front = Tiles[0];

    if( Front.X <= 0 + TILE_SIZE/2 || Front.X + TILE_SIZE >= WWIDTH - TILE_SIZE/2 ||
        Front.Y <= 0 + TILE_SIZE/2 || Front.Y + TILE_SIZE >= WHEIGHT - TILE_SIZE/2){

        Tiles.clear();

        int X = WWIDTH/4;
        int Y = WHEIGHT/2;

        for(unsigned int I = 0; I < 10; I++){

            CTile tempTile(X,Y,0,3);
            Tiles.push_back(tempTile);

            X -= TILE_SIZE;
        }
        direction = RIGHT;
    }

    Move();
}
//---------------------------------------------------------------------------
void CSnake::OnRender(){

    for(CTile Tile : Tiles){
        SDL_Rect dest = {Tile.X,Tile.Y,TILE_SIZE,TILE_SIZE};
        SDL_RenderCopy(Renderer,SnakeTexture,NULL,&dest);
    }
}
//---------------------------------------------------------------------------
void CSnake::Move(){

    std::vector<CTile>::iterator it = Tiles.begin();
    Tiles.pop_back();

    CTile Front = Tiles[0];
    int X, Y;

    switch(direction){

        case RIGHT:
            X = Front.X + TILE_SIZE;
            Y = Front.Y;
            break;
        case LEFT:
            X = Front.X - TILE_SIZE;
            Y = Front.Y;
            break;
        case UP:
            X = Front.X;
            Y = Front.Y - TILE_SIZE;
            break;
        case DOWN:
            X = Front.X;
            Y = Front.Y + TILE_SIZE;
            break;
        default:
            break;
    }

    CTile newFront(X,Y,0,3);
    Tiles.insert(it,newFront);
}
//---------------------------------------------------------------------------
void CSnake::grow(){

    int X, Y;
    int last = Tiles.size() - 1;

    X = Tiles[last].X - TILE_SIZE;
    Y = Tiles[last].Y - TILE_SIZE;

    CTile tempTile(X,Y,0,3);

    Tiles.push_back(tempTile);

}
//---------------------------------------------------------------------------



























