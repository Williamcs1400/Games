#ifndef __SPRITE__
#define __SPRITE__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include "SDL_include.h"
    #define INCLUDE_SDL_IMAGE
    #define INCLUDE_SDL_MIXER
    #include <SDL2/SDL.h>
    #include <Component.hpp>
    #include <GameObject.hpp>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_mixer.h>

    class Sprite : public Component{
        public:
            Sprite(GameObject& associated);
            Sprite(const char* file, GameObject& associated);
            ~Sprite();
            void Open(const char* file);
            void setClip(int x, int y, int w, int h);
            void render();
            int getWidth();
            int getHeight();
            bool isOpen();
            void Update(float dt);
            bool Is(string type);

        private:
            SDL_Texture* texture;
            SDL_Rect clipRect;
            int width ;
            int height;
    };

#endif