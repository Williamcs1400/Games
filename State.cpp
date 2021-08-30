#include "State.hpp"

using namespace std;

State::State(){
    quitRequested = false;
    bg = Sprite(); 
}

void State::LoadAssets(){
    
}

void State::Update(float dt){
    if(SDL_QuitRequested() == true){
        quitRequested = true;
    }
}

void State::Render(){
}

bool State::getQuitRequested(){ 
    return quitRequested;
}