#ifndef __CAMERA__
#define __CAMERA__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include "SDL_include.h"
    #include "GameObject.hpp"
    #include "Vec2.hpp"
    #define INCLUDE_SDL_IMAGE
    #define INCLUDE_SDL_MIXER

    using namespace std;

    class Camera{
        public:
            void Follow(GameObject* newFocus);
            void Unfollow();
            void Update(float dt);
            Vec2 pos;
            Vec2 speed;
        private:
            GameObject* focus;
    };

#endif