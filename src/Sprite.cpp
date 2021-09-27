#include "../include/Sprite.hpp"
#include "../include/Game.hpp"
#include "../include/Resources.hpp"

using namespace std;

Sprite::Sprite(GameObject& associated) : Component(associated){
    texture = nullptr;
}

Sprite::Sprite(const char* file, GameObject& associated) : Component(associated){
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite(){
    // if(isOpen()){
    //     SDL_DestroyTexture(texture);
    // }
}

void Sprite::Open(string file){
    // if(isOpen()){
    //     SDL_DestroyTexture(texture);
    // }

    // Game& game = Game::getInstance();
    if(!isOpen()){
        texture = Resources::GetImage(file);
    }

    if(texture == nullptr){
        clog << "Open error: " << SDL_GetError() << endl;
    }else{
        clog << "IMG_LoadTexture sucess: " << file << endl;
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

void Sprite::Render(){
    // SDL_Rect rect;
    // rect.x = associated.box.x;
    // rect.y = associated.box.y;
    // rect.w = width;
    // rect.h = height;

    // Game& game = Game::getInstance();
    // if(isOpen()){
    //     SDL_RenderCopy(game.getRenderer(), texture, &clipRect, &rect);
    // }
    Render(associated.box.x, associated.box.y);
    
}

void Sprite::Render(int x, int y){
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = clipRect.w;
    rect.h = clipRect.h;

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

void Sprite::Update(float dt) {

}

bool Sprite::Is(string type) {
    return type == "Sprite";
}

bool Sprite::isOpen(){
    if(texture != nullptr){
        return true;
    }
    return false;

};