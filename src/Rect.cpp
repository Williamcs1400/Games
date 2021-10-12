#include "../include/Rect.hpp"

using namespace std;

Rect::Rect(){
    x = 0;
    y = 0;
    w = 0;
    h = 0;
}

Rect::Rect(float x, float y, float w, float h){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

void Rect::operator+= (const Vec2& vec) {
    x += vec.x;
    y += vec.y;
}


bool Rect::contains(const Vec2& point){
    if((point.x >= x) && (point.y >= y) && (point.x <= x + w) && (point.y <= y + h)){
        return true;
    }
    return false;
}