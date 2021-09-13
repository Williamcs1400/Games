#include "../include/GameObject.hpp"

GameObject::GameObject(){
    isDead = false;
}

GameObject::~GameObject(){
    for(int i = components.size() - 1; i <= 0; i--){
        // components.push_back()
    }
}

void GameObject::Update(float dt){
    for(int i = 0; i < components.size() - 1; i++){
        components.at(i)->Update(dt);
    }
}

void GameObject::Render(){
    for(int i = 0; i < components.size() - 1; i++){
        components.at(i)->Render();
    }
}

bool GameObject::IsDead(){
    return isDead;
}

void GameObject::RequestDelete(){
    isDead = true;
}

void GameObject::AddComponent(Component* cpt){
    components.push_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt){
    for(int i = 0; i < components.size() - 1; i++){
        if(components[i] == cpt){
            // components.erase(i);
        }
    }
}

Component* GameObject::GetComponent(string type){
    
}
