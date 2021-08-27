#include <iostream>
#include <string>
#include <stdlib.h>
#include "Game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

using namespace std;

class State{
    public:
        void state(){
            SDL_QuitRequested();
        }

        void LoadAssets(){

        }

        void Update(float dt){

        }

        void Render(){

        }

        bool QuitRequested(){ 
        }
};



int main(int argc, char *argv[]){



    return 1;
}
