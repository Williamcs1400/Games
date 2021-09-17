#include "../include/Vec2.hpp"

Vec2::Vec2(){
    x = 0.0f;
    y = 0.0f;
}

Vec2::Vec2(float x, float y){
    this->x = x;
    this->y = y;
}

Vec2 Vec2::GetRotated(float angle){
    float angleX = (x * cos(angle)) - (y * sin(angle));
    float angleY = (y * cos(angle)) - (x * sin(angle));
    
    return Vec2(angleX, angleY);
}

Vec2 Vec2::operator+(const Vec2& vec){
    return Vec2(x + vec.x, y + vec.y);
}

Vec2 Vec2::operator-(const Vec2& vec){
    return Vec2(x - vec.x, y - vec.y);
}

Vec2 operator*(float value, const Vec2& vec){
    return Vec2(vec.x * value, vec.y * value);
}
