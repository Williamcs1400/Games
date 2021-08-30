#include "Sprite.hpp"
#include "Game.hpp"

using namespace std;
Sprite::Sprite(){
    texture = nullptr;
}

Sprite::Sprite(const char* file){
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite(){
    
}

void Sprite::Open(const char* file){
    Game* game;
    game = game->getInstance();
    texture =  IMG_LoadTexture(game->getRenderer(), file);
    if(texture == nullptr){
        clog << "Open error: " << SDL_GetError() << endl;
    }else{
        clog << "IMG_LoadTexture sucess: " << SDL_GetError() << endl;
        int query = SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

    }
}

void Sprite::setClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::render(int x, int y){
    Game* game;
    game = game->getInstance();
    //SDL_RenderCopy(game->getRenderer(), texture, clipRect, )
}

int Sprite::getWidth(){
    return width;
}

int Sprite::getHeight(){
    return height;
}

bool Sprite::isOpen(){
    if(texture != nullptr){
        return true;
    }
    return false;

};