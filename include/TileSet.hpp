#ifndef __TILESET__
#define __TILESET__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include "Sprite.hpp"
    
    using namespace std;

    class TileSet{
        public:
            TileSet(int tileWidth, int tileHeight, string file);
            void RenderTile(int index, float x, float y);
            int GetTileWidth();
            int GetTileHeight();
            
        private:
            Sprite* tileSet;
            int rows;
            int columns;
            int tileWidth;
            int tileHeight;
    };

#endif