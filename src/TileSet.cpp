#include "../include/TileSet.hpp"

TileSet::TileSet(int tileWidth, int tileHeight, string file){
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;

    tileSet.Open(file.c_str());

}

void TileSet::RenderTile(unsigned index, float x, float y){

    if(index >= 0 && index <= (tileHeight * tileWidth)){
        tileSet.setClip(rows, columns, tileWidth, tileHeight);
    }else{
        clog << 'Invalid index' << endl;
    }
}
