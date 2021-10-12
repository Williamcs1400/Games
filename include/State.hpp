#ifndef __STATE__
#define __STATE__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include <ctime>
    #include "SDL_include.h"
    #include <vector>
    #include <memory>
    #define INCLUDE_SDL_IMAGE
    #define INCLUDE_SDL_MIXER
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_mixer.h>
    #include "Sprite.hpp"
    #include "Music.hpp"
    #include "GameObject.hpp"
    #include "Face.hpp"
    #include "Vec2.hpp"
    #include "Sound.hpp"
    #include "TileMap.hpp"
    #include "InputManager.hpp"
    #include "CameraFollower.hpp"
    
    using namespace std;

    class State{
        public:
            State();
            ~State();
            void LoadAssets();
            void Update(float dt);
            void Render();
            bool getQuitRequested();
        private:
            void AddObject(int mouseX, int mouseY);
            Sprite *bg;
            Music* music;
            bool quitRequested = true;
            vector<std::unique_ptr<GameObject>> objectArray;

    };

#endif