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
        clog << "SDL_Init Sucess" << endl;

        /*if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) != 0){
            clog << "IMG_Init Sucess" << endl;
        }else{
        clog << "IMG_Init Failure" << endl;
        clog << IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) << endl;
        }*/
        
    }else{
        clog << "SDL_Init Failure" << endl;
    }

    return 1;
}
