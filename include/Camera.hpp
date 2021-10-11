#ifndef __CAMERA__
#define __CAMERA__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include "SDL_include.h"
    #include "GameObject.hpp"
    #include "Vec2.hpp"
    #include "InputManager.hpp"
    #define INCLUDE_SDL_IMAGE
    #define INCLUDE_SDL_MIXER

    using namespace std;

    class Camera{
        public:
            static void Follow(GameObject* newFocus);
            static void Unfollow();
            static void Update(float dt);
            static Vec2 pos;
            static Vec2 speed;
        private:
            static GameObject* focus;
    };

#endif