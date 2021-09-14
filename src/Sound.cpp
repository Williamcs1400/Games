#include "../include/Sound.hpp"

Sound::Sound(GameObject& associated){
    chunk = nullptr;
}

Sound::Sound(GameObject& associated, string file){
    Sound(*associated);
    Open(file);
}

Sound::~Sound(){
    if(chunk != nullptr){
        Mix_HaltChannel(channel);
        Mix_FreeChunk(chunk);
    }
}

void Sound::Play(int times = 1){
    channel = Mix_PlayChannel(-1, chunk, times);
}

void Sound::Stop(){
    if(chunk != nullptr){
        Mix_HaltChannel(channel);
    }
}

void Sound::Open(string file){
    Mix_Chunk* aux = Mix_LoadWAV(file.c_str());

    if(aux == nullptr){
        clog << 'Error Mix_LoadWAV = nullptr';
    }else{
        clog << 'Success Mix_LoadWAV';
    }
}

bool Sound::IsOpen(){

}

void Sound::Update(float dt){

}

void Sound::Render(){

}

void Sound::Is(string type){

}