#ifndef __MUSIC__
#define __MUSIC__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include "SDL_include.h"
    #define INCLUDE_SDL_IMAGE
    #define INCLUDE_SDL_MIXER
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_mixer.h>

    class Music{
        public:
            Music();
            Music(const char* file);
            ~Music();
            void Play(int times);
            void Stop(int msToStop);
            void Open(const char* file);
            bool IsOpen();

        private:
            Mix_Music* music;
    };

#endif