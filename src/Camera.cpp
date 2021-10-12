#include "../include/Camera.hpp"

// init
Vec2 Camera::pos;
Vec2 Camera::speed;
GameObject* Camera::focus = nullptr;

void Camera::Follow(GameObject* newFocus){
    focus = newFocus;
}

void Camera::Unfollow(){
    focus = nullptr;
}

void Camera::Update(float dt){
    if(focus == nullptr){
        InputManager& inputManager = InputManager::GetInstance();
        
        if(inputManager.IsKeyDown(UP_ARROW_KEY)) {
            speed += Vec2(0,-1);
        }
        if(inputManager.IsKeyDown(DOWN_ARROW_KEY)) {
            speed += Vec2(0,1);
        }
        if(inputManager.IsKeyDown(LEFT_ARROW_KEY)) {
            speed += Vec2(-1,0);
        }
        if(inputManager.IsKeyDown(RIGHT_ARROW_KEY)){
            speed += Vec2(1, 0);
        }
        pos += dt * 400 * speed.Normalized();
        speed = Vec2(0,0);

    }
    else {
        pos = focus->box.center() - Vec2(512,300);
    }
}
