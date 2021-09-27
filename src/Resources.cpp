#include "../include/Resources.hpp"
#include "../include/Game.hpp"

// INIT
unordered_map<string, SDL_Texture*> Resources::imageTable;
unordered_map<string, Mix_Music*> Resources::musicTable;
unordered_map<string, Mix_Chunk*> Resources::soundTable;

SDL_Texture* Resources::GetImage(string file){
    auto local = imageTable.find(file);

    if(local != imageTable.end()){
        return local->second;
    }

    Game& game = Game::getInstance();
    imageTable[file] = IMG_LoadTexture(game.getRenderer(), file.c_str());
    SDL_Texture* texture = IMG_LoadTexture(game.getRenderer(), file.c_str());

    if(texture == nullptr){
        clog << "ERROR GetImage";
    }

    return texture;
}

void Resources::ClearImages(){
    for(auto& i : Resources::imageTable){
        SDL_DestroyTexture(i.second);
    }
    Resources::imageTable.clear();

}

Mix_Music* Resources::GetMusic(string file){
    auto local = Resources::musicTable.find(file);

    if(local != Resources::musicTable.end()){
        return local->second;
    }

    musicTable[file] = Mix_LoadMUS(file.c_str());
    Mix_Music* music = Mix_LoadMUS(file.c_str());

    return music;
}

void Resources::ClearMusics(){
    for(auto& i : Resources::musicTable){
        Mix_FreeMusic(i.second);
    }
    Resources::musicTable.clear();
}

Mix_Chunk* Resources::GetSound(string file){
    auto local = Resources::soundTable.find(file);

    if(local != Resources::soundTable.end()){
        return local->second;
    }

    soundTable[file] = Mix_LoadWAV(file.c_str());
    Mix_Chunk* chunk = Mix_LoadWAV(file.c_str());

    return chunk;
}

void Resources::ClearSounds(){
    for(auto& i : Resources::soundTable){
        Mix_FreeChunk(i.second);
    }
    Resources::soundTable.clear();

}
