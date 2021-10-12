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
    SDL_Event evt;

    SDL_GetMouseState(&mouseX, &mouseY);
    quitRequested = false;
    updateCounter++;

    while(SDL_PollEvent(&evt)) {
        if(evt.type == SDL_QUIT) {
            quitRequested = true;
        }

        if(evt.type == SDL_MOUSEBUTTONDOWN) {
            mouseState[evt.button.button] = true;
            mouseUpdate[evt.button.button] = updateCounter;
        }

        if(evt.type == SDL_MOUSEBUTTONUP) {
            mouseState[evt.button.button] = false;
            mouseUpdate[evt.button.button] = updateCounter;
        }

        if(evt.type == SDL_KEYDOWN && !evt.key.repeat) {
            keyState[evt.key.keysym.sym] = true;
            keyUpdate[evt.key.keysym.sym] = updateCounter;
        }

        if(evt.type == SDL_KEYUP) {
            keyState[evt.key.keysym.sym] = false;
            keyUpdate[evt.key.keysym.sym] = updateCounter;
        }
    }
}

bool InputManager::KeyPress(int key){
    if((keyState.find(key) != keyState.end()) && (keyUpdate.at(key) == updateCounter) && keyState.at(key)){
        return true;
    }
    return false;
}

bool InputManager::KeyRelease(int key){
    if((keyState.find(key) != keyState.end()) && (keyUpdate.at(key) == updateCounter) && !keyState.at(key)){
        return true;
    }
    return false;
}

bool InputManager::IsKeyDown(int key){
    if((keyState.find(key) != keyState.end()) && (keyUpdate.at(key) < updateCounter) && keyState.at(key)){
            return true;
        }
        return false;
}

bool InputManager::MousePress(int button){
    if((mouseUpdate[button] == updateCounter) && mouseState[button]){
            return true;
        }
        return false;
}

bool InputManager::MouseRelease(int button){
    if((mouseUpdate[button] == updateCounter) && !mouseState[button]){
        return true;
    }
    return false;
}

bool InputManager::IsMouseDown(int button){
    if((mouseUpdate[button] < updateCounter) && mouseState[button]){
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
