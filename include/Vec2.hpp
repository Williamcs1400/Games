#ifndef __VEC__
#define __VEC__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include <math.h>

    #define PI 3.14159265359;

    using namespace std;

    class Vec2{
        public:
            Vec2();
            Vec2(float x, float y);
            Vec2 GetRotated(float angle);
            Vec2 operator+ (const Vec2& vec);
            Vec2 operator- (const Vec2& vec);
            friend Vec2 operator* (float value, const Vec2& vec);
            float x;
            float y;
    };

#endif