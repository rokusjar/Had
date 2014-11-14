#include <iostream>
#include <fstream>
//------------------------------------------------------------------------
/**
    Vygeneruje mapu pro Snake2
*/
int main(){

    int width = 1024;
    int height = 768;
    int tile = 8;

    std::ofstream inFile;
    inFile.open("mainMap.map");

    for(int I = 0; I < height/tile; I++){

        for(int J = 0; J < width/tile; J++){

            if (I == 0 || I == height/tile - 1){
                if (J == width/tile - 1) {
                    inFile << "2\n";
                    continue;
                }else {
                    inFile << "2 ";
                    continue;
                }
            }

            if (J == 0 || J == width/tile - 1){
                if (J == width/tile - 1) {
                    inFile << "2\n";
                    continue;
                }else {
                    inFile << "2 ";
                    continue;
                }
            }

            inFile << "1 ";
        }
    }

    inFile.flush();
    inFile.close();
    return 0;
};
