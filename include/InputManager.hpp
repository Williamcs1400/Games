#ifndef __INPUTMANAGER__
#define __INPUTMANAGER__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include "SDL_include.h"
    #define INCLUDE_SDL_IMAGE
    #define INCLUDE_SDL_MIXER
    #include <unordered_map>

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
            int GetMouseX();
            bool QuitRequested();
            InputManager& GetInstance();
        private:
            InputManager();
            ~InputManager();
            bool mouseState[6]; 
            int mouseUpdate[6];
            unordered_map<int, bool> keyState;
            unordered_map<int, int> keyState;
            bool quitRequested;
            int updateCounter;
            int mouseX;
            int mouseY;
    };

#endif