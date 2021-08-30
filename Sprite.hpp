#ifndef __SPRITE__
#define __SPRITE__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include "SDL_include.h"
    #define INCLUDE_SDL_IMAGE
    #define INCLUDE_SDL_MIXER
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_mixer.h>

    class Sprite{
        public:
            Sprite();
            Sprite(const char* file);
            ~Sprite();
            void Open(const char* file);
            void setClip(int x, int y, int w, int h);
            void render(int x, int y);
            int getWidth();
            int getHeight();
            bool isOpen();

        private:
            SDL_Texture* texture;
            SDL_Rect clipRect;
            int width;
            int height;
    };

#endif