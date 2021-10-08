#ifndef __CAMERAFOLLOWER__
#define __CAMERAFOLLOWER__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include "SDL_include.h"
    #include "GameObject.hpp"
    #include "Component.hpp"
    #define INCLUDE_SDL_IMAGE
    #define INCLUDE_SDL_MIXER

    using namespace std;

    class CameraFollower : public Component{
        public:
            CameraFollower(GameObject* go);
            void Update(float dt);
            void Render();
            bool Is(string type);
    };

#endif