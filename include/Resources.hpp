#ifndef __RESOURCES__
#define __RESOURCES__

    #include "SDL_include.h"
    #define INCLUDE_SDL_IMAGE
    #define INCLUDE_SDL_MIXER
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_mixer.h>
    #include <string>
    #include <unordered_map>
    #include <iostream>
    #include <stdlib.h>

    using namespace std;

    class Resources{
        public:
            static SDL_Texture* GetImage(string file);
            static void ClearImages();
            static Mix_Music* GetMusic(string file);
            static void ClearMusics();
            static Mix_Chunk* GetSound(string file);
            static void ClearSounds();

        private:
            static unordered_map<string, SDL_Texture*> imageTable;
            static unordered_map<string, Mix_Music*> musicTable;
            static unordered_map<string, Mix_Chunk*> soundTable;
    };

#endif