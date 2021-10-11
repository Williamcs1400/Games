#include "../include/Face.hpp"

Face::Face(GameObject& associated) : Component(associated){
    hitpoints = 30;
}

void Face::Damage(int damage){
    hitpoints -= damage;
    if(hitpoints <= 0){
        Sound* sound = (Sound*) associated.GetComponent("Sound");
        if(sound != nullptr){
            sound->Play();
            associated.RequestDelete();
        }
        //associated.sound
    }
}

void Face::Update(float dt){
    InputManager& inputManager =  InputManager::GetInstance();
    if(inputManager.MousePress(LEFT_MOUSE_BUTTON)){
        float mouseX = (float) inputManager.GetMouseX();
        float mouseY = (float) inputManager.GetMouseY();
        if(associated.box.contains(Camera::pos + Vec2(mouseX, mouseY))){
            if(!this->IsDead()){
                this->Damage(rand() % 10 + 10);
            }
        }
    }
}

void Face::Render(){

}

bool Face::Is(string type){
    if(type == "Face"){
        return true;
    }
    return false;
}

bool Face::IsDead() {
    if(hitpoints <= 0){
        return true;
    }
    return false;
}