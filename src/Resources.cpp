#include "../include/Resources.hpp"
#include "../include/Game.hpp"

// INIT
std::unordered_map<std::string, SDL_Texture*> Resources::imageTable;
std::unordered_map<std::string, Mix_Music*> Resources::musicTable;
std::unordered_map<std::string, Mix_Chunk*> Resources::soundTable;

SDL_Texture* Resources::GetImage(string file){
    auto local = Resources::imageTable.find(file);

    if(local != Resources::imageTable.end()){
        return local->second;
    }

    Game& game = Game::getInstance();
    SDL_Texture* texture = IMG_LoadTexture(game.getRenderer(), file.c_str());

    if(texture == nullptr){
        clog << "Error Resources::GetImage" << endl;
        return nullptr;
    }else{
        Resources::imageTable.emplace(file, texture);
        return texture;
    }
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

    Mix_Music* music = Mix_LoadMUS(file.c_str());

    if(music == nullptr){
        clog << "Error Resources::GetMusic" << endl;
        return nullptr;
    }else{
        Resources::musicTable.emplace(file, music);
        return music;
    }
}

void Resources::ClearMusics(){
    for(auto& i : Resources::musicTable){
        Mix_FreeMusic(i.second);
    }
}

Mix_Chunk* Resources::GetSound(string file){
    auto local = Resources::soundTable.find(file);

    if(local != Resources::soundTable.end()){
        return local->second;
    }

    Mix_Chunk* chunk = Mix_LoadWAV(file.c_str());

    if(chunk == nullptr){
        clog << "Error Resources::GetMusic" << endl;
        return nullptr;
    }else{
        Resources::musicTable.emplace(file, chunk);
        return chunk;
    }
}

void Resources::ClearSounds(){
    for(auto& i : Resources::soundTable){
            Mix_FreeChunk(i.second);
        }
}
