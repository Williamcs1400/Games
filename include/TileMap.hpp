#ifndef __TILEMAP__
#define __TILEMAP__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include <vector>
    #include "GameObject.hpp"
    #include "Component.hpp"
    #include "TileSet.hpp"
    
    using namespace std;

    class TileMap : Component{
        public:
            TileMap(GameObject& associated, string file, TileSet* tileSet);
            void load(string file);
            void SetTileSet(TileSet* tileSet);
            int& At(int x, int y, int z);
            void Render();
            void RenderLayer(int layer, int cameraX, int cameraY);
            int GetWidth();
            int GetHeight();
            int GetDepth();
            
        private:
            vector<int> tileMatrix; 
            TileSet* tileSet;
            int mapWidth;
            int mapHeight;
            int mapDepth;
    };

#endif