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
            void GetRotated(float angle);
            float x;
            float y;
    };

#endif