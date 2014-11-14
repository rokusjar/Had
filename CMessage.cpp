#include "CMessage.h"
#include <sstream>
//---------------------------------------------------------------------------
void CMessage::show(std::string message){

    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Message",message.c_str(),NULL);
}
//---------------------------------------------------------------------------
void CMessage::showformat(std::string message, std::vector<std::string> mvariables){

    std::stringstream stream;
    unsigned int sum = 0;

    for (char i : message) {
        if (i == '{') sum++;
    }

    if (sum < mvariables.size() || sum > mvariables.size()) {
        CMessage::showformat("error in showformat:\n {}",{message});
        return;
    }

    int index = 0;

    for (char j : message) {

        if ( j == '{' ){
            stream << mvariables[index];
            index++;
            continue;
        }
        if ( j == '}' ) {
            continue;
        }
        if ( j != '{' || j != '}' ) {
            stream << j;
        }
    }

    message = stream.str();
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Message",message.c_str(),NULL);
}
//---------------------------------------------------------------------------
