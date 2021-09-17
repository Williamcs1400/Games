#ifndef __COMPONENT__
#define __COMPONENT__

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include "GameObject.hpp"
    using namespace std;

    class GameObject;

    class Component{
        public:
            explicit Component(GameObject& associated);
            virtual ~Component();
            virtual void Update(float dt) = 0;
            virtual void Render() = 0;
            virtual bool Is(string type) = 0;
        protected:
            GameObject& associated;

    };

#endif