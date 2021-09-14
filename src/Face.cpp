#include "../include/Face.hpp"

Face::Face(GameObject& associated) : Component(associated){
    hitpoints = 30;
}

void Face::Damage(int damage){
    hitpoints -= damage;
    if(hitpoints <= 0){
        associated.RequestDelete();
        //associated.sound
    }
}

void Face::Update(float dt){

}

void Face::Render(){

}

bool Face::Is(string type){
    if(type == "Face"){
        return true;
    }
    return false;
}