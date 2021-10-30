#ifndef __RECT__
#define __RECT__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include "Vec2.hpp"

    class Rect{
        public:
            Rect();
            Rect(float x, float y, float w, float h);
            friend Rect operator+(const Rect& rec, const Vec2& vec);
            friend Rect operator+(const Vec2& vec, const Rect& rec);
            friend Rect operator-(const Rect& rec, const Vec2& vec);
            void operator+=(const Vec2& rec);
            void operator-=(const Vec2& rec);
            float distance_to(const Rect& distance);
            bool contains(const Vec2& vec);
            Vec2 center() const;
            float x;
            float y;
            float w;
            float h;
    };

#endif