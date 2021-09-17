#include "../include/Game.hpp"

using namespace std;

Game* Game::instance = nullptr;

Game::Game(const char* title, int width, int height){
    if(instance == nullptr){
        instance = this;
    }else{
        clog << "ERROR!!!" << endl;
    }

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) == 0){
        clog << endl << "SDL_Init Sucess" << endl << endl;

        // Flags for init
        int IMG_Flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
        int MIX_Flags = MIX_INIT_MP3 | MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_OGG;

        // Init SLD_IMG
        if(IMG_Init(IMG_Flags)){
            clog << "IMG_Init Sucess" << endl << endl;
        }else{
            clog << "IMG_Init Failure: " << IMG_GetError() << endl << endl;
            return;
        }

        // Init SDL_Mix
        if(Mix_Init(MIX_Flags)){
            clog << "Mix_Init Sucess" << endl;

            if(!Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)){
                clog << "Mix_OpenAudio Sucess" << endl;
            }else{
                clog << "Mix_OpenAudio Failure: " << Mix_GetError() << endl;
                return;
            }
            
            if(Mix_AllocateChannels(32)){
                clog << "Mix_AllocateChannels Sucess" << endl << endl;
            }else{
                clog << "Mix_AllocateChannels Failure: " << Mix_GetError() << endl << endl;
                return;
            }
            
        }else{
            clog << "Mix_Init Failure: " << Mix_GetError() << endl;
            return;
        }
    }else{
        clog << "SDL_Init Failure" << endl;
    }
    
    SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if(window == nullptr){
        clog << "SDL_Window error: " << SDL_GetError() << endl;
    }else{
        clog << "window: " << window << endl;
    }

    renderer =  SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(window == nullptr){
        clog << "SDL_Renderer error: " << SDL_GetError() << endl;
    }else{
        clog << "renderer: " << renderer << endl << endl;
    }

    state = new State();
}

Game::~Game(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    IMG_Quit();
    SDL_Quit();
}

SDL_Renderer* Game::getRenderer(){
    return renderer;
}

State& Game::getState(){
    return *state;
}

Game& Game::getInstance(){
    if(instance == nullptr){
        clog << endl << "Create a new instance" << endl;
        instance = new Game("William Coelho da Silva - 180029274", 1024, 600);
        clog << endl << "instance: " << instance << endl;
        return *instance;
    }else{
        //clog << endl << "Instance already exists" << endl;
        return *instance;
    }
}

void Game::Run(){
    clog << endl << "Run the game: " << state->getQuitRequested() << endl;
    while(state->getQuitRequested()){
        state->Update(0);
        state->Render();
        SDL_RenderPresent(getRenderer());
        SDL_Delay(33);
    }
    clog << endl << "Error: " << SDL_GetError() << endl;
}

int main(int argc, char *argv[]){

    // Call the constructor
    Game& game = Game::getInstance();
    game.Run();
            
    return 1;
}
