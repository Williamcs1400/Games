#include "../include/Sprite.hpp"
#include "../include/Game.hpp"

using namespace std;

Sprite::Sprite(){
    texture = nullptr;
}

Sprite::Sprite(const char* file){
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite(){
    if(isOpen()){
        SDL_DestroyTexture(texture);
    }
}

void Sprite::Open(const char* file){
    if(isOpen()){
        SDL_DestroyTexture(texture);
    }

    Game& game = Game::getInstance();
    texture =  IMG_LoadTexture(game.getRenderer(), file);
    if(texture == nullptr){
        clog << "Open error: " << SDL_GetError() << endl;
    }else{
        clog << "IMG_LoadTexture sucess: " << SDL_GetError() << endl;
        int query = SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
        clog << "query: " << query << endl;
        setClip(0, 0, width, height);
    }
}

void Sprite::setClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::render(int x, int y){
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

    Game& game = Game::getInstance();
    if(isOpen()){
        SDL_RenderCopy(game.getRenderer(), texture, &clipRect, &rect);
    }
    
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