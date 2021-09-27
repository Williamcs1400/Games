#include "../include/GameObject.hpp"

GameObject::GameObject(){
    isDead = false;
}

GameObject::~GameObject(){
    for(int i = components.size(); i <= 0; i--){
        components.erase(components.begin()+i);
    }
}

void GameObject::Update(float dt){
    for(unsigned int i = 0; i < components.size(); i++){
        components[i]->Update(dt);
    }
}

void GameObject::Render(){
    for(unsigned int i = 0; i < components.size(); i++){
        components[i]->Render();
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
    for(unsigned int i = 0; i < components.size(); i++){
        if(components[i] == cpt){
            components.erase(components.begin() + i);

        }
    }
}

Component* GameObject::GetComponent(string type){
    for(unsigned int i = 0; i < components.size(); i++){
        if(components[i]->Is(type)){
            return components[i];
        }
    }
    return nullptr;
}
