#ifndef __INPUTMANAGER__
#define __INPUTMANAGER__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include "SDL_include.h"
    #include <SDL2/SDL_events.h>
    #define INCLUDE_SDL
    #define INCLUDE_SDL_IMAGE
    #define INCLUDE_SDL_MIXER
    #include <unordered_map>

    #define LEFT_ARROW_KEY SDLK_LEFT
    #define RIGHT_ARROW_KEY SDLK_RIGHT
    #define UP_ARROW_KEY SDLK_UP
    #define DOWN_ARROW_KEY SDLK_DOWN
    #define ESCAPE_KEY SDLK_ESCAPE
    #define SPACE_KEY SDLK_SPACE
    #define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT

    using namespace std;

    class InputManager{
        public:
            void Update();
            bool KeyPress(int key);
            bool KeyRelease(int key);
            bool IsKeyDown(int key);
            bool MousePress(int button);
            bool MouseRelease(int button);
            bool IsMouseDown(int button);
            int GetMouseX();
            int GetMouseY();
            bool QuitRequested();
            static InputManager& GetInstance();
        private:
            InputManager();
            ~InputManager();
            bool mouseState[6]; 
            int mouseUpdate[6];
            unordered_map<int, bool> keyState;
            unordered_map<int, int> keyUpdate;
            bool quitRequested;
            int updateCounter;
            int mouseX;
            int mouseY;
    };

#endif