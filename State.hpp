#ifndef __STATE__
#define __STATE__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include "SDL_include.h"
    #define INCLUDE_SDL_IMAGE
    #define INCLUDE_SDL_MIXER
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_mixer.h>
    #include "Sprite.hpp"

    class State{
        public:
            State();
            void LoadAssets();
            void Update(float dt);
            void Render();
            bool getQuitRequested();
        private:
            Sprite bg;
            // Music music;
            bool quitRequested;
    };

#endif