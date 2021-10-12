#ifndef __RECT__
#define __RECT__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include "Vec2.hpp"

    class Rect{
        public:
            bool contains(const Vec2& point);
            Rect();
            Rect(float x, float y, float w, float h);
            void operator+= (const Vec2& vec);
            float x;
            float y;
            float w;
            float h;
    };

#endif