#ifndef __FACE__
#define __FACE__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include <Component.hpp>
    #include <GameObject.hpp>
    using namespace std;

    class Face : public Component{
        public:
            Face(GameObject& associated);
            void Damage(int damage);
            void Update(float dt);
            void Render();
            bool Is(string type);
        private:
            int hitpoints;
    };

#endif