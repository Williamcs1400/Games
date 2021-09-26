#include "../include/TileSet.hpp"

TileSet::TileSet(int tileWidth, int tileHeight, string file){
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;

    GameObject* GO = new GameObject();
    tileSet = new Sprite(file.c_str(), *GO);

    if(tileSet->isOpen()){
        rows = tileSet->getWidth();
        columns = tileSet->getHeight();
    }

}

void TileSet::RenderTile(unsigned index, float x, float y){
    if(index >= 0 && index <= (tileHeight * tileWidth)){
        int rowTile = (index % rows) * tileWidth;
        int columnsTile = (index / rows) * tileWidth;
        tileSet->setClip(rowTile, columnsTile, tileWidth, tileHeight);
        tileSet->Render(x, y);
    }else{
        clog << 'Invalid index' << endl;
    }
}

int TileSet::GetTileHeight(){
    return tileHeight;
}

int TileSet::GetTileWidth(){
    return tileWidth;
}
