#include "../include/Sound.hpp"

Sound::Sound(GameObject& associated) : Component(associated){
    chunk = nullptr;
}

Sound::Sound(GameObject& associated, string file) : Sound(associated){
    Open(file);
}

Sound::~Sound(){
    if(chunk != nullptr){
        Mix_HaltChannel(channel);
        Mix_FreeChunk(chunk);
    }
}

void Sound::Play(int times){
    channel = Mix_PlayChannel(-1, chunk, times - 1 );
}

void Sound::Stop(){
    if(chunk != nullptr){
        Mix_HaltChannel(channel);
    }
}

void Sound::Open(string file){
    chunk = Mix_LoadWAV(file.c_str());

    if(!IsOpen()){
        clog << "Error Mix_LoadWAV = nullptr -> " << SDL_GetError() << endl;
    }else{
        clog << "Success Mix_LoadWAV" << endl;;
    }
}

bool Sound::IsOpen(){
    if(chunk != nullptr){
        return true;
    }
    return false;
}

void Sound::Update(float dt){

}

void Sound::Render(){

}

bool Sound::Is(string type){
    if(type == "Sound"){
        return true;
    }
    return false;
}

bool Sound::IsPlaying() {
    if(IsOpen() && channel >= 0 && channel <= 32){
        return Mix_Playing(channel);
    }
    return false;
}