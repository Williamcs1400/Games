#ifndef __COMPONENT__
#define __COMPONENT__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include <GameObject.hpp>
    using namespace std;

    class Component{
        public:
            Component(GameObject& associated);
            virtual ~Component();
            void virtual Update(float dt);
            void virtual Render();
            bool virtual Is(string type);
        protected:
            GameObject& associated;

    };

#endif