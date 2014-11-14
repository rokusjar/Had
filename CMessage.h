//===========================================================================
/*
    Very basic class for printing error messages using SDL_ShowSimpleMessageBox

    showformat function enables you format std::string using {}

    Example:

    CMessage::showformat("Name: {}, Age: {}",{"John", "23"});

    NOTE!
    c++11 must be used - Initializer lists
*/
//===========================================================================
#ifndef CMESSAGE_H_INCLUDED
#define CMESSAGE_H_INCLUDED

#include <SDL.h>
#include <string>
#include <vector>
//---------------------------------------------------------------------------

class CMessage{

    public:

        static void show(std::string message);

        static void showformat(std::string message, std::vector<std::string> mvariables);
};

#endif // CMESSAGE_H_INCLUDED
