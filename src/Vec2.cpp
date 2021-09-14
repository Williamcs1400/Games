#include "../include/Vec2.hpp"


Vec2::Vec2(){
    x = 0.0f;
    y = 0.0f;
}

Vec2::Vec2(float x, float y){
    this->x = x;
    this->y = y;
}

void Vec2::GetRotated(float angle){
    float angleX = (x * cos(angle)) - (y * sin(angle));
    float angleY = (y * cos(angle)) - (x * sin(angle));
    x = angleX;
    y = angleY;
}