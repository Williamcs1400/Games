#include "../include/InputManager.hpp"

InputManager& InputManager::GetInstance(){
    static InputManager instanceInputManager;
    return instanceInputManager;
}

InputManager::InputManager(){
    for(int i = 0; i < 6; i++){
        mouseState[i] = false;
        mouseUpdate[i] = 0;
    }
    updateCounter = 0;
    mouseX = 0;
    mouseY = 0;
    quitRequested = false;
}

InputManager::~InputManager(){
}

void InputManager::Update(){
    clog << "InputManager::Update";
    SDL_Event event;

    updateCounter++;
    quitRequested = false;

    SDL_GetMouseState(&mouseX, &mouseY);

    while(SDL_PollEvent(&event)){
        if(event.type == SDL_MOUSEBUTTONUP){
            mouseUpdate[event.button.button] = updateCounter;
            mouseState[event.button.button] = false;
        }

        if(event.type == SDL_MOUSEBUTTONDOWN){
            mouseUpdate[event.button.button] = updateCounter;
            mouseState[event.button.button] = true;
        }

        if(event.type == SDL_KEYUP){
            mouseUpdate[event.key.keysym.sym] = updateCounter;
            mouseState[event.key.keysym.sym] = false;
        }
        
        if(event.type == SDL_KEYDOWN && !event.key.repeat){
            mouseUpdate[event.key.keysym.sym] = updateCounter;
            mouseState[event.key.keysym.sym] = true;
        }
        
        if(event.type == SDL_QUIT){
            quitRequested = true;
        }
        clog << "InputManager::Update AAAAAAAAAAAAAA";

    }
}

bool InputManager::KeyPress(int key){
    if((keyState.find(key) != keyState.end()) && (keyUpdate.at(key) == updateCounter) && (keyState.at(key) == updateCounter)){
        return true;
    }
    return false;
}

bool InputManager::KeyRelease(int key){
    if((keyState.find(key) != keyState.end()) && (keyUpdate.at(key) == updateCounter) && !(keyState.at(key) == updateCounter)){
        return true;
    }
    return false;
}

bool InputManager::IsKeyDown(int key){
    if((keyState.find(key) != keyState.end()) && (keyUpdate.at(key) < updateCounter) && (keyState.at(key) < updateCounter)){
            return true;
        }
        return false;
}

bool InputManager::MousePress(int button){
    if((mouseUpdate[button] == updateCounter) && (mouseState[button] == updateCounter)){
            return true;
        }
        return false;
}

bool InputManager::MouseRelease(int button){
    if((mouseUpdate[button] == updateCounter) && !(mouseState[button] == updateCounter)){
        return true;
    }
    return false;
}

bool InputManager::IsMouseDown(int button){
    if((mouseUpdate[button] < updateCounter) && (mouseState[button] < updateCounter)){
        return true;
    }
    return false;
}

int InputManager::GetMouseX(){
    return mouseX;
}

int InputManager::GetMouseY(){
    return mouseY;
}

bool InputManager::QuitRequested(){
    return quitRequested;
}
