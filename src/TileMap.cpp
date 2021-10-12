#include "../include/TileMap.hpp"

TileMap::TileMap(GameObject& associated, string file, TileSet* tileSet) : Component(associated){
    this->tileSet = tileSet;
    load(file);
}

void TileMap::load(string file){
    string newFile, aux;
    ifstream ifStreamFile(file);

    if(ifStreamFile.is_open()){
        while (getline(ifStreamFile, aux)){
            newFile += aux;
        }
        ifStreamFile.close();
    }

    size_t i = 0;
    while ((i = newFile.find(",")) != string::npos){
        string str = newFile.substr(0, i);
        tileMatrix.push_back(std::stoi(str) - 1);
        newFile.erase(0, i + 1);
    }

    mapWidth = tileMatrix[0] + 1;
    mapHeight = tileMatrix[1] + 1;
    mapDepth = tileMatrix[2] + 1;

    tileMatrix.erase(tileMatrix.begin(), tileMatrix.begin() + 3);
}

void TileMap::SetTileSet(TileSet* tileSet){
    this->tileSet = tileSet;
}

int& TileMap::At(int x, int y, int z){
    return tileMatrix.at(x + (y * mapWidth) + (z * mapWidth * mapHeight));
}

void TileMap::Render(){
    int i;
    for(i = 0; i < mapDepth; i++){
        RenderLayer(i, Camera::pos.x * (i + 1), Camera::pos.y * (i + 1));
    }
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY){
    int i, j;
    for(i = 0; i < mapWidth; i++){
        for(j = 0; j < mapWidth; j++){
            int index = tileMatrix[At(j, i, layer)];
            float x = (tileSet->GetTileWidth() * j) - cameraX;
            float y = (tileSet->GetTileHeight() * i) - cameraY;
            tileSet->RenderTile(index, x, y);
        }
    }
}

void TileMap::Update(float dt){

}

bool TileMap::Is(string type){
    if(type == "TileMap"){
        return true;
    }
    return false;
}

int TileMap::GetWidth(){
    return mapWidth;
}

int TileMap::GetHeight(){
    return mapHeight;
}

int TileMap::GetDepth(){
    return mapDepth;
}



