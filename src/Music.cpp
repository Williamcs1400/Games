#include "../include/Music.hpp"
#include "../include/Resources.hpp"

using namespace std;

Music::Music(){
    music = nullptr;
}

Music::Music(const char* file){
    music = nullptr;
    Open(file);
}

Music::~Music(){
    if(IsOpen()){
        Stop(1.5);
        Mix_FreeMusic(music);
    }
}

void Music::Play(int times){
    int play = Mix_PlayMusic(music, times);
    clog << "play: " << play << endl;

}

void Music::Stop(int msToStop){
    int stop = Mix_FadeOutMusic(msToStop);
    clog << "stop: " << stop << endl;

}

void Music::Open(string file){
    // music = Mix_LoadMUS(file);
    // if(music == nullptr){
    //     clog << endl << "Error Mix_LoadMUS" << endl;
    // }
    music = Resources::GetMusic(file);
}

bool Music::IsOpen(){
    if(music == nullptr){
        return false;
    }
    return true;
}