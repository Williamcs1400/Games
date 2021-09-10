#include "../include/State.hpp"

using namespace std;

State::State(){
    quitRequested = true;
    bg = new Sprite("./images/title.jpg"); 
    music = new Music("./musics/stageState.ogg");
    music->Play(-1);
}

void State::LoadAssets(){
    
}

void State::Update(float dt){
    if(SDL_QuitRequested()){
        quitRequested = false;
    }
}

void State::Render(){
    bg->render(0, 0);
}

bool State::getQuitRequested(){ 
    return quitRequested;
}