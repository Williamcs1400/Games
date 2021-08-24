#include <iostream>
#include <string>
#include <stdlib.h>
#include "Game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

using namespace std;

int main(int argc, char *argv[]){
    
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) == 0){
        clog << "SDL_Init Sucess" << endl << endl;

        // Flags for init
        int IMG_Flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
        int MIX_Flags = MIX_INIT_MP3 | MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_OGG;

        // Init SLD_IMG
        if(IMG_Init(IMG_Flags)){
            clog << "IMG_Init Sucess" << endl << endl;
        }else{
            clog << "IMG_Init Failure: " << IMG_GetError() << endl << endl;
            return 0;
        }

        // Init SDL_Mix
        if(Mix_Init(MIX_Flags)){
            clog << "Mix_Init Sucess" << endl;

            if(!Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)){
                clog << "Mix_OpenAudio Sucess" << endl;
            }else{
                clog << "Mix_OpenAudio Failure: " << Mix_GetError() << endl;
                return 0;
            }
        }else{
            clog << "Mix_Init Failure: " << Mix_GetError() << endl;
            return 0;
        }

        // Open window
        

    }else{
        clog << "SDL_Init Failure" << endl;
    }

    return 1;
}
