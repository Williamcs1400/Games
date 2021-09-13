#ifndef __SOUND__
#define __SOUND__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include "GameObject.hpp"
    #include <vector>
    #define INCLUDE_SDL_MIXER
    #include <SDL2/SDL_mixer.h>
    using namespace std;

    class Sound{
        public:
            Sound(GameObject& associated);
            Sound(GameObject& associated, string file);
            ~Sound();
            void Play(int times = 1);
            void Stop();
            void Open(string file);
            bool IsOpen();
            void Update(float dt);
            void Render();
            void Is(string type);

        private:
            Mix_Chunk* chunk;
            int channel;
    };

#endif