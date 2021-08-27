#include <iostream>
#include <string>
#include <stdlib.h>
#include "Game.h"
#include "State.cpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

using namespace std;

//SDL_Renderer* state = nullptr;
SDL_Renderer* renderer = nullptr;

void Game(const char * title, int width, int height){
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) == 0){
        clog << endl << "SDL_Init Sucess" << endl << endl;

        // Flags for init
        int IMG_Flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
        int MIX_Flags = MIX_INIT_MP3 | MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_OGG;

        // Init SLD_IMG
        if(IMG_Init(IMG_Flags)){
            clog << "IMG_Init Sucess" << endl << endl;
        }else{
            clog << "IMG_Init Failure: " << IMG_GetError() << endl << endl;
            return;
        }

        // Init SDL_Mix
        if(Mix_Init(MIX_Flags)){
            clog << "Mix_Init Sucess" << endl;

            if(!Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)){
                clog << "Mix_OpenAudio Sucess" << endl;
            }else{
                clog << "Mix_OpenAudio Failure: " << Mix_GetError() << endl;
                return;
            }
            
            if(Mix_AllocateChannels(32)){
                clog << "Mix_AllocateChannels Sucess" << endl << endl;
            }else{
                clog << "Mix_AllocateChannels Failure: " << Mix_GetError() << endl << endl;
                return;
            }
            
        }else{
            clog << "Mix_Init Failure: " << Mix_GetError() << endl;
            return;
        }
    }else{
        clog << "SDL_Init Failure" << endl;
    }
    
    SDL_Window* window = SDL_CreateWindow(title, 0, 0, 0, width, height);
    if(window == nullptr){
        clog << "SDL_Window error: " << SDL_GetError() << endl;
    }else{
        clog << "window" << window << endl;
    }

    renderer =  SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(window == nullptr){
        clog << "SDL_Renderer error: " << SDL_GetError() << endl;
    }else{
        clog << "renderer" << renderer << endl << endl;
    }
}


void DestructorGame(){
}

SDL_Renderer* getRenderer(){
    return renderer;
}

void run(){

    State* a = new State;
    a->state();

    while(a->QuitRequested()){

        //a->Update();
        //a->Render();

        SDL_Delay(33);
        
    }
}

int main(int argc, char *argv[]){
    // Open window
    Game("William Coelho da Silva - 180029274", 1024, 600);

    return 1;
}
