#include "../include/TileSet.hpp"

TileSet::TileSet(int tileWidth, int tileHeight, string file){
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;

    GameObject* GO = new GameObject();
    tileSet = new Sprite(file.c_str(), *GO);

    if(tileSet->isOpen()){
        rows = tileSet->getWidth() / tileWidth;
        columns = tileSet->getHeight() / tileHeight;
    }

}

void TileSet::RenderTile(int index, float x, float y){
    if(index >= 0 && index <= (rows * columns)){
        int rowTile = (index % columns) * tileWidth;
        int columnsTile = (index / columns) * tileHeight;
        tileSet->setClip(rowTile, columnsTile, tileWidth, tileHeight);
        tileSet->Render(x, y);
    }
}

int TileSet::GetTileHeight(){
    return tileHeight;
}

int TileSet::GetTileWidth(){
    return tileWidth;
}
