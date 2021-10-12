#ifndef __GAME__
#define __GAME__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include "SDL_include.h"
    #define INCLUDE_SDL_IMAGE
    #define INCLUDE_SDL_MIXER
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_mixer.h>
    #include "State.hpp"
    #include "InputManager.hpp"

    class Game{
        public:
            ~Game();
            SDL_Renderer* getRenderer();
            static Game& getInstance();
            State& getState();
            void Run();
            float GetDeltaTime();
        private:
            Game(const char* title, int width, int height);
            void CalculateDeltaTime();
            static Game* instance;
            SDL_Renderer* renderer;
            SDL_Window* window;
            State* state;
            int frameStart;
            float dt;
    };

#endif