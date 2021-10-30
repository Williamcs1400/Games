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

Rect operator+(const Rect& rec, const Vec2& vec) {
    return Rect(
        rec.x + vec.x,
        rec.y + vec.y,
        rec.w,
        rec.h
    );
}

Rect operator+(const Vec2& vec, const Rect& rec) {
    return Rect(
        rec.x + vec.x,
        rec.y + vec.y,
        rec.w,
        rec.h
    );
}

void Rect::operator+= (const Vec2& vec) {
    x += vec.x;
    y += vec.y;
}

Rect operator-(const Rect& rec, const Vec2& vec) {
    return Rect(
        rec.x - vec.x,
        rec.y - vec.y,
        rec.w,
        rec.h
    );
}

void Rect::operator-=(const Vec2& vec) {
    x -= vec.x;
    y -= vec.y;
}

float Rect::distance_to(const Rect& to) {
    return this->center().distance(to.center());
}

Vec2 Rect::center() const {
    return Vec2(
        x + (w / 2),
        y + (h / 2)
    );
}

bool Rect::contains(const Vec2& vec){
    if((vec.x >= x) && (vec.y >= y) && (vec.x <= x + w) && (vec.y <= y + h)){
        return true;
    }
    return false;
}