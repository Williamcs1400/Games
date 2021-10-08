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

void InputManager::Update(){
    
}